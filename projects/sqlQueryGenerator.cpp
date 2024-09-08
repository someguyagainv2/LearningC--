// THIS IS UNFINISHED AND I'M STILL WORKING ON

#include <iostream>

using std::cout, std::cin, std::string;

void output(string text) { // makes life a bit easier
    cout << text << "\n";
}

void helpCommand(string command) {
    output("List of command options");
    string out;

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

string orderByStatement() {

    int numberOfFields;

    string statement = "ORDER BY ";

    output("Max of 10 fields");
    cout << "How many fields to be ordered: ";

    cin >> numberOfFields;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
    }
    else {
        for (int index = 0; index < numberOfFields; index++) {
            string tempValue;
            cout << "Field Name: ";
            cin >> tempValue;
            if (index + 1 == numberOfFields) {
                statement = statement + tempValue;
            }
            else {
                statement = statement + tempValue + ",";
            }
            
        }

        string typeOfOrder;
        cout << "ascending Or descending: ";
        cin >> typeOfOrder;

        if (typeOfOrder != "ascending" && typeOfOrder != "descending") {
            cout << "No Valid Paramater Provided Last Attempt";
            cin >> typeOfOrder;
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

void returnData() {
    output("Started returnData command use the help command ");
    string criteriaStatement = ""; // E.g WHERE 1=1
    string selectStatement = "SELECT ";
    string orderStatement = "";

    bool criteria = false; // If there's a criteria we'll change this to true
    bool orderByState = false;

    int amountOfFields;

    while (true) {
        string command;
        cout << "root@SQLGenerator > returnData > ";
        cin >> command;

        if (command == "setreturnFields") {
            output("Max of 10 fields");
            cout << "How many fields to be returned: ";
            cin >> amountOfFields;

            if (cin.fail()) {
                output("Invalid Input");
                cin.clear();
                cin.ignore(256, '\n');

            }
            else {
                for (int index = 0; index < amountOfFields; index++) {
                    string tempValue;
                    cout << "Field Name: ";
                    cin >> tempValue;
                    if (index + 1 == amountOfFields) { selectStatement = selectStatement + tempValue; }
                    else { selectStatement = selectStatement + tempValue + ","; }
                }

                cout << "What table should we query from: ";
                string tableName;
                cin >> tableName;

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

    string finishedQuery = selectStatement;

    if (criteria) {
        finishedQuery = finishedQuery + "\n" + criteriaStatement;
    }

    if (orderByState) {
        finishedQuery = finishedQuery + "\n" + orderStatement;
    }


    output("Finished Query");
    cout << finishedQuery << "\n";

}

void dropDatabase() {
    string databaseName;
    cout << "What's the database name: ";
    cin >> databaseName;

    output("Finished Query");
    output("DROP DATABASE "+databaseName+";");
}

void dropTable() {
    string tableName;
    cout << "What's the table name: ";
    cin >> tableName;

    output("Finished Query");
    output("DROP TABLE " + tableName + ";");
}

auto commandCaller(string command, string locationFired) {
    if (locationFired == "main") {
        if (command == "help") { helpCommand("main"); return ""; }
        else if (command == "exit") { return "break"; }
        else if (command == "deleteDatabase") { dropDatabase(); }
        else if (command == "returnData") { returnData(); }
        else if (command == "deleteTable") { dropTable(); }
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

        string command;
        
        cout << "root@SQLGenerator > ";
        cin >> command;

        if (commandCaller(command, "main") == "break") {
            break;
        }
    }
    
}
