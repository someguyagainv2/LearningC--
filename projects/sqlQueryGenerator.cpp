
// THIS IS UNFINISHED AND I'M STILL WORKING ON

#include <iostream>

void output(std::string text) { // makes life a bit easier
    std::cout << text << "\n";
}

void helpCommand(std::string command) {
    output("List of command options");
    std::string out;

    if (command == "main") {
        out = "help \n\
returnData\n\
insertData\n\
createDatabase\n\
createTable\n\
deleteTable\n\
deleteColumn\n\
deleteDatabase\n\
exit";
    }
    else if (command == "returnData") {
        out = "help\n\
back\n\
setCriteria\n\
setreturnFields\n\
setOrder\n\
finishQuery";
    }
    output(out);
}

std::string orderByStatement() {

    int numberOfFields;

    std::string statement = "ORDER BY ";

    output("Max of 10 fields");
    std::cout << "How many fields to be ordered: ";

    std::cin >> numberOfFields;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
    else {
        for (int index = 0; index < numberOfFields; index++) {
            std::string tempValue;
            std::cout << "Field Name: ";
            std::cin >> tempValue;
            if (index + 1 == numberOfFields) {
                statement = statement + tempValue;
            }
            else {
                statement = statement + tempValue + ",";
            }
            
        }

        std::string typeOfOrder;
        std::cout << "ascending Or descending: ";
        std::cin >> typeOfOrder;

        if (typeOfOrder != "ascending" && typeOfOrder != "descending") {
            std::cout << "No Valid Paramater Provided Last Attempt";
            std::cin >> typeOfOrder;
        }
        else if (typeOfOrder == "ascending") {
            typeOfOrder = "ASC";
        }
        else if (typeOfOrder == "descending") {
            typeOfOrder = "DESC";
        }

        statement = statement + " " + typeOfOrder;

        return statement;
    }
}

std::string returnData() {
    output("Started returnData command use the help command ");
    std::string criteriaStatement = ""; // E.g WHERE 1=1
    std::string selectStatement = "SELECT ";
    std::string orderStatement = "";

    bool criteria = false; // If there's a criteria we'll change this to true
    bool orderByState = false;

    int amountOfFields;

    while (true) {
        std::string command;
        std::cout << "root@SQLGenerator > returnData > ";
        std::cin >> command;

        if (command == "setreturnFields") {
            output("Max of 10 fields");
            std::cout << "How many fields to be returned: ";
            std::cin >> amountOfFields;

            if (std::cin.fail()) {
                output("Invalid Input");
                std::cin.clear();
                std::cin.ignore(256, '\n');

            }
            else {
                for (int index = 0; index < amountOfFields; index++) {
                    std::string tempValue;
                    std::cout << "Field Name: ";
                    std::cin >> tempValue;
                    if (index + 1 == amountOfFields) { selectStatement = selectStatement + tempValue; }
                    else { selectStatement = selectStatement + tempValue + ","; }
                }

                std::cout << "What table should we query from: ";
                std::string tableName;
                std::cin >> tableName;

                selectStatement = selectStatement + " FROM " + tableName;
            }
        }
        else if (command == "setOrder") {
            orderStatement = orderByStatement(); // will return the query for ORDER BY LINE
            orderByState = true;
            // Handling it in seperate function to avoid nesting to much
        }
        else if (command == "finishQuery") { break; }
        else if (command == "help") { helpCommand("returnData"); }
    }

    std::string finishedQuery = selectStatement;

    if (criteria) {
        finishedQuery = finishedQuery + "\n" + criteriaStatement;
    }

    if (orderByState) {
        finishedQuery = finishedQuery + "\n" + orderStatement;
    }


    output("Finished Query");
    std::cout << finishedQuery << "\n";

    return "";
}

auto commandCaller(std::string command, std::string locationFired) {
    if (locationFired == "main") {
        if (command == "help") { helpCommand("main"); return ""; }
        else if (command == "exit") { return "break"; }
        else if (command == "returnData") { returnData(); }
        else { output("Unknown Command"); }
    }
    else if (locationFired == "returnData") {
        if (command == "help") { helpCommand("returnData"); }
    }
}


int main()
{
    output("SQL Query Generator Basic");
    output("For this to work the program will ask series of questions to ultimately make you an SQL Query perfectly.");
    output("To get started use the help command in terminal provided below");
    while (true) {

        std::string command;
        
        std::cout << "root@SQLGenerator > ";
        std::cin >> command;

        if (commandCaller(command, "main") == "break") {
            break;
        }
    }
    
}
