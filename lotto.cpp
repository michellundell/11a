/**
 * @file lotto.cpp
 * @author Daniel Örhill (daniel.orhill@studerande.movant.se)
 * @brief Lottery checker
 * @version 1
 * @date 2022-11-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <unistd.h>
#include <sstream>
#include <vector>

/**
 * main entry point of the program.
 * @param[in] argc Number of command line arguments.
 * @param[in] argv An array of pointers to null terminated arrays of characters (command line arguments).
 * @param[out] returns 0 on success.
 */
int main(int argc, char **argv)
{
    // Declare variables
    int opt;
    int num;
    int lottoMatch = 0;
    int extraMatch = 0;
    std::vector<int> luckyNums;
    std::vector<int> extraNums;
    std::vector<int> myLuckyNums;
    std::string mainLot;
    std::string myLot;

    while ((opt = getopt(argc, argv, "ec:l:")) != -1)
    {
        switch (opt)
        {
        case 'c':
            mainLot = optarg;
            break;
        case 'l':
            myLot = optarg;
            break;
        case 'e':
            std::cout << "exemple: /.lotto.exe -c 1,2,3,4,5,6,7/11,12,13,14 -l 1,2,3,4,5,11,12\n";
            std::cout << "5 + 2 correct";
            exit(-1);
            break;
        default:
            std::cout << "Usage " << argv[0] << "\n\t-c {The lottery numbers[7]/The extra lottery numbers[4]}\n\t-l {My lottery numbers[7]}\n\t-e {Exemple}";
            exit(-1);
            break;
        }
    }

    std::stringstream nums(mainLot);
    std::stringstream mynums(myLot);
    std::string temp;

    // Fill vectors with numbers
    for (int i = 0; i < 6; i++)
    {
        getline(nums, temp, ',');
        num = atoi(temp.c_str());
        luckyNums.push_back(num);
    }
    getline(nums, temp, '/');
    num = atoi(temp.c_str());
    luckyNums.push_back(num);
    for (int i = 0; i < 4; i++)
    {
        getline(nums, temp, ',');
        num = atoi(temp.c_str());
        extraNums.push_back(num);
    }
    for (int i = 0; i < 7; i++)
    {
        getline(mynums, temp, ',');
        num = atoi(temp.c_str());
        myLuckyNums.push_back(num);
    }

    // Check for matching numbers
    for (int i = 0; i < myLuckyNums.size(); i++)
    {
        for (int j = 0; j < luckyNums.size(); j++)
        {
            if (myLuckyNums[i] == luckyNums[j])
            {
                lottoMatch++;
            }
        }
        for (int e = 0; e < extraNums.size(); e++)
        {
            if (myLuckyNums[i] == extraNums[e])
            {
                extraMatch++;
            }
        }
    }

    // Show user the result
    std::cout << lottoMatch << " + " << extraMatch << " correct numbers\n";

    return 0;
}
