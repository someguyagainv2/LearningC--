// THIS IS UNFINISHED AND I'M STILL WORKING ON

#include <iostream>

using std::cout;
using std::cin;
using std::string;

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
    /*
    Finished CHECKLIST
    returnData working on still
    deleteTable
    deleteDatabase
    exit*/

    else if (command == "returnData") {
        out = "help\n\
setCriteria\n\
setreturnFields\n\
setOrder\n\
finishQuery";
    }
    /*
        Finished CHECKLIST
        setCriteria Working on
        setreturnFields
        setOrder
        finishQuery*/
    
    else if (command == "returnData.setCriteria") {
        out = "equals\n\
bigger\n\
less\n\
bigger_equals >= \n\
less_equals <= \n\ ";
    }
    /*
    Finished CHECKLIST
    bigger
    less
    equals
    less_equals
    bigger_equals*/
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

string setCriteria() {
    output("what should the criteria check");
    output("Use help to see options");
    string finishedStatement;

    while (true) {
        string command;
        cout << "root@SQLGenerator > returnData > setCriteria > ";
        cin >> command;

        if (cin.fail()) { cin.clear(); cin.ignore(256, '\n'); continue; } // I'm hoping implementing this continue will then skip running everything past this point

        string isFirstField;
        string FirstFieldName; // THESE 2 VALUES MAY BE EMPTY
        string SecondFieldName;
        string isSecondField;

        output("Answer following questions with y or n");
        cout << "Is the first value a field? ";
        cin >> isFirstField;

        cout << "Is the second value a field? ";
        cin >> isSecondField;

        if (isFirstField == "y" && isSecondField == "y") { // if both values are a field

            cout << "Field Name #1: ";
            cin >> FirstFieldName;

            cout << "Field Name 2#: ";
            cin >> SecondFieldName;
        }
        else if (isFirstField == "y" && isSecondField == "n") {

            cout << "Field Name #1 Name: ";
            cin >> FirstFieldName;
        }

        if (command == "help") { helpCommand("returnData.setCriteria"); }
        else if (command == "equals") {

            if (isFirstField == "y" && isSecondField == "y") { // if both values are a field
                finishedStatement = "WHERE " + FirstFieldName + "=" + SecondFieldName;
            }
            else if (isFirstField == "y" && isSecondField == "n") {
                while (true) {
                    string fieldType;

                    cout << "What type of value is 2nd value \n";
                    cout << "Type help to get a list\n";

                    cout << "root@SQLGenerator > returnData > setCriteria >  fieldType > ";
                    cin >> fieldType;

                    if (cin.fail()) { cin.clear(); cin.ignore(256, '\n'); }
                    
                    if (fieldType == "help") {
                        output("BOOL\n\
NUMBER\n\
STRING\n\ ");

                    }
                    else if (fieldType == "BOOL") {
                        string boolType;
                        cout << "True Or False: ";
                        cin >> boolType;

                        finishedStatement = "WHERE " + FirstFieldName + "=" + boolType;
                        break;
                    }
                    else if (fieldType == "STRING") {
                        string valueToDetect;

                        cout << "What's the string value to detect: ";
                        cin >> valueToDetect;

                        finishedStatement = "WHERE " + FirstFieldName + "='" + valueToDetect + "'";
                        break;
                    }
                    else if (fieldType == "NUMBER") {
                        string valueToDetect;

                        cout << "What's the integer's value to detect: ";
                        cin >> valueToDetect;

                        finishedStatement = "WHERE " + FirstFieldName + "=" + valueToDetect;
                        break;
                    }
                    else { output("Invalid Type"); }
                }
            }
            else { output("Input Y or N."); }

            if (!finishedStatement.empty()) {
                break;
            }
        }
        else if (command == "bigger") {
            if (isFirstField == "y" && isSecondField == "y") { // if both values are a field

                finishedStatement = "WHERE " + FirstFieldName + ">" + SecondFieldName;
            }
            else if (isFirstField == "y" && isSecondField == "n") {
                string value;

                cout << "What's the number the field should be bigger than? ";
                cin >> value;

                finishedStatement = "WHERE " + FirstFieldName + ">" + value;
            }
            else if (isFirstField == "n" && isSecondField == "n") {
                string firstValue;
                string secondValue;

                output("Example Format \nFirst Number: 2\nSecond Number:5\nResult:WHERE 2>5");
                cout << "What's the first number which will be bigger than other? ";
                cin >> firstValue;

                cout << "What's the second number which will be less than the first number? ";
                cin >> secondValue;

                finishedStatement = "WHERE " + firstValue + ">" + secondValue;
            }
        }
        else if (command == "less") {
            if (isFirstField == "y" && isSecondField == "y") { // if both values are a field

                finishedStatement = "WHERE " + FirstFieldName + "<" + SecondFieldName;
            }
            else if (isFirstField == "y" && isSecondField == "n") {
                string value;

                cout << "What's the number the field should be less than? ";
                cin >> value;

                finishedStatement = "WHERE " + FirstFieldName + "<" + value;
            }
            else if (isFirstField == "n" && isSecondField == "n") {
                string firstValue;
                string secondValue;

                output("Example Format \nFirst Number: 2\nSecond Number:5\nResult:WHERE 2<5");
                cout << "What's the first number which will be less than second number? ";
                cin >> firstValue;

                cout << "What's the second number which will be bigger than first number? ";
                cin >> secondValue;

                finishedStatement = "WHERE " + firstValue + "<" + secondValue;
            }
        }
        else if (command == "bigger_equals") {
            if (isFirstField == "y" && isSecondField == "y") { // if both values are a field

                finishedStatement = "WHERE " + FirstFieldName + ">=" + SecondFieldName;
            }
            else if (isFirstField == "y" && isSecondField == "n") {
                string value;

                cout << "What's the number the field should be bigger than or equal to? ";
                cin >> value;

                finishedStatement = "WHERE " + FirstFieldName + ">=" + value;
            }
            else if (isFirstField == "n" && isSecondField == "n") {
                string firstValue;
                string secondValue;

                output("Example Format \nFirst Number: 2\nSecond Number:5\nResult:WHERE 2>=5");
                cout << "What's the first number which will be bigger than other or equal to? ";
                cin >> firstValue;

                cout << "What's the second number which will be less than the first number or equal to? ";
                cin >> secondValue;

                finishedStatement = "WHERE " + firstValue + ">=" + secondValue;
            }
        }
        else if (command == "less_equals") {
            if (isFirstField == "y" && isSecondField == "y") { // if both values are a field

                finishedStatement = "WHERE " + FirstFieldName + "<=" + SecondFieldName;
            }
            else if (isFirstField == "y" && isSecondField == "n") {
                string value;

                cout << "What's the number the field should be less than or equal to? ";
                cin >> value;

                finishedStatement = "WHERE " + FirstFieldName + "<=" + value;
            }
            else if (isFirstField == "n" && isSecondField == "n") {
                string firstValue;
                string secondValue;

                output("Example Format \nFirst Number: 2\nSecond Number:5\nResult:WHERE 2<=5");
                cout << "What's the first number which will be less than or equal to the other? ";
                cin >> firstValue;

                cout << "What's the second number which will be less than or equal to first value? ";
                cin >> secondValue;

                finishedStatement = "WHERE " + firstValue + "<=" + secondValue;
            }
        }
    }

    return finishedStatement;
}

void returnData() {
    output("Started returnData command use the help command ");
    string criteriaStatement = ""; // E.g WHERE 1=1
    string selectStatement = "SELECT ";
    string orderStatement = "";

    bool criteria = false; // If there's a criteria we'll change this to true
    bool orderByState = false;

    int amountOfFields;

    // I do want to rewrite bunch of this to use direct pointers to variables so the functions don't nessecarily need to return anything and will adjust the variable accordingly

    while (true) { // To keep it reoccuring if I used consistent function calls there wouldn't nessecarily be an end to the script and I couldn't exactly break out unless using return state
        
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
        else if (command == "setCriteria") { criteriaStatement = setCriteria(); criteria = true; } // Using these func calls in technicalities I could create reference then send it through as ptr allowing me to edit values
        else { output("Invalid Command"); }
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
