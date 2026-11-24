#include "Manager.h"
#include <sstream>

using namespace std;

Manager::Manager() : graph(nullptr)
{

}

Manager::~Manager()
{
    delete graph;
}

void Manager::printSuccess(const string& command, const string& body)
{

}

void Manager::printErrorCode(int code)
{

}

bool Manager::run(const char* commandFile, const char* logFile)
{
    fin.open(commandFile);
    fout.open(logFile, ios::app);

    //file open and command check
    if (fin.is_open()) {
        string line;
        while (getline(fin, line)) {
            try {
                if (!line.empty() && line.back() == '\r') line.pop_back();

                vector<string> args = split(line, ' ');
                if (args.empty()) continue;
                string command = args[0];
                args.erase(args.begin());

                if (command == "LOAD") {
                    if (args.size() != 1) throw 100;
                    LOAD(args[0].c_str());
                }
                else if (command == "PRINT") {
                    if (args.size() != 0) throw 200;
                    PRINT();
                }
                //else if (command == "UPDATE") {
                //    if (args.size() != 2) throw 300;
                //    UPDATE(args);
                //}
                //else if (command == "SEARCH") {
                //    SEARCH(args);
                //}
                //else if (command == "PRINT") {
                //    PRINT(args);
                //}
                //else if (command == "EXIT") {
                //    EXIT();
                //    break;
                //}
                else {
                    throw 1000;
                }
            }
            catch (int error_code) {
                printErrorCode(error_code);
            }
        }
    }
    else {
        // Error code for command file not found
        fout << "Error: not found the command file";
    }

    //file close
    fin.close();
}

bool Manager::LOAD(const char* filename)
{
    // List graph LOAD
    if (string(filename) == string("graph_L.txt")) {
        ifstream input;
        input.open("graph_L.txt");
        if (!input.is_open()) throw 100;  // not exist error
        
        char g;
        input >> g;
        if (g != 'L') throw 100;    // not List graph

        //size
        int s;
        input >> s;
        delete graph;
        graph = new ListGraph(0, s);

        // input data
        string line;
        while (getline(input, line)) {
            // empty line
            if (line.empty()) continue;

            stringstream ss(line);
            int from, to, w;

            if (ss >> to) {
                // two argument -> to & weight
                if (ss >> w) {
                    graph->insertEdge(from, to, w);
                }
                // one argument -> from
                else {
                    from = to;
                }
            }
        }

        input.close();
    }
    // Matrix graph LOAD
    else if (string(filename) == string("graph_M.txt")) {
        ifstream input;
        input.open("graph_M.txt");
        if (!input.is_open()) throw 100;  // not exist error

        char g;
        input >> g;
        if (g != 'M') throw 100;    // not matrix graph

        //size
        int s;
        input >> s;
        delete graph;
        graph = new MatrixGraph(0, s);
        string line;
        int w;

        // input data
        stringstream ss(line);
        for (int i = 0; i < s; i++) {
            getline(input, line);
            stringstream ss(line);
            for (int j = 0; j < s; j++) {
                ss >> w;
                if (w != 0) graph->insertEdge(i, j, w);
            }
        }
    }
    // file name error
    else throw 100;
}

bool Manager::PRINT()
{
    if (graph == nullptr) throw 200;

    fout << "=========PRINT=========\n";
    graph->printGraph(&fout);
    fout << "=======================\n\n";
}

bool Manager::mBFS(char option, int vertex)
{

}

bool Manager::mDFS(char option, int vertex)
{

}

bool Manager::mDIJKSTRA(char option, int vertex)
{

}

bool Manager::mKRUSKAL()
{

}

bool Manager::mBELLMANFORD(char option, int start, int end)
{

}

bool Manager::mFLOYD(char option)
{

}

bool Manager::mSORT(char option, int vertex, char order, char method)
{

}

//argument split function
vector<string> Manager::split(const string& line, char delim) {
    vector<string> result;
    string temp;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] != delim) temp.push_back(line[i]);
        else {
            if (!temp.empty()) result.push_back(temp);
            temp.clear();
        }
    }
    if (!temp.empty()) result.push_back(temp);

    return result;
}