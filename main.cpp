#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>
#include <fstream>
#include <iomanip>
#include "hashp.h"
#include <algorithm>

using namespace std;






/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {
   // std::cout << "Hello, World!" << std::endl;
    string dir = string(argv[1]);
    vector<string> files = vector<string>();
    vector<string> wordsInFile = vector<string>();
    int fileNum = 0;
    getdir(dir,files);

    files.erase(files.begin());
    files.erase(files.begin());


    //for (unsigned int i = 0;i < files.size();i++) {
    //    cout << i << files[i] << endl;
   // }


    Hash h(100000);
    //std::queue<string> work;
    ifstream inFile;
    for(int i =0; i <files.size(); i++) {


        //cout << files[1] << endl;

        string filePath = dir + "/" + files[i];

        inFile.open(filePath.c_str());

        if (!inFile)
            cout << "not opening " << endl;

        string something;
        int count = 0;
        while (inFile >> something) {
            string idk = something;
            wordsInFile.push_back(idk);
            count++;

        }
        inFile.close();
        inFile.clear();
        string please;



        //for (int k=  0; please[k+6] != wordsInFile.back(); k++)

        while(!wordsInFile.empty())
        {
            int k =0;


                for (int j = k; j < k + 6; j++)
                {

                    please = please + " " + wordsInFile[j];


                }

                for (int x = 0, len = please.size(); x < len; x++)
                {


                    if (ispunct(please[x]) || (please[x] == ' ') || !isalnum(please[x])) {
                        please.erase(x--, 1);
                        len = please.size();
                    }

                }
                transform(please.begin(), please.end(), please.begin(), ::toupper);
             // cout << please << endl;
               h.insertItem(fileNum, please);


            please = "";
            k++;
            wordsInFile.erase(wordsInFile.begin());

        }

        fileNum ++;
    }
     h.displayArray(files.size(), files);

/*
    cout << work.size() << endl;

    while(!work.empty())
    {
        std:: cout << work.front() << endl;
        work.pop();
        std:: cout <<endl;
    }
*/
    return 0;
}