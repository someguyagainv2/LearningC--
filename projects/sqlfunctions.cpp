#include <iostream>
#include <ctype.h>
// #include "Curlfuncs.h" I'll make another proj for this code but right now it needs rewriting it's messy and doesn't use SSL
// Vulnerability Man In Middle Attack which no one wants.

const string website = "http://IP:PORT/URI";
const string password = "yourpassword";

// MISC FUNCTIONS

bool isString(string checkValue) {
    bool found = true;
    for (auto x = checkValue.begin(); x != checkValue.end(); x++) {
        if (isdigit(*x)) {
            found = false;
            break;
        }
    }
    return found;
}

// MAIN QUERY HANDLER

string queryDB(string query = "empty") {
    if (query == "empty") { std::cerr << "No query provided!"; return ""; }

    string headers[1] = { "Content-Type: application/json" };
    string value = "{\"csrf\":\""+ password+ "\", \"query\": \"" + query + "\"}";
    const std::string data = sendRequest(website, "post", 1, headers, value.c_str());
    return data;
}

// QUERY STRUCTURER

void insertData(string tableName, string columnNames[], int columnSize, string values[], int valuesSize=1) {
    string query = "INSERT INTO " + tableName + "(";

    for (int i = 0; i < columnSize; i++) {
        if (i + 1 == columnSize) { query += columnNames[i];  }
        else { query += columnNames[i] + ","; }
    }

    query += ") VALUES(";
    for (int i = 0; i < valuesSize; i++) {
        bool tempValue = isString(values[i]);

        if (tempValue) {
        
            query += "'" + values[i] + "'";
        }
        else {
            query += values[i];
        }

        if (i + 1 == valuesSize) { query += ");"; } 
        else { query += ", "; }
        
    }

    queryDB(query);
}

string returnValues(string columnNames[], string tableName, int columnSize) {
    string query = "SELECT ";

    for (int i = 0; i < columnSize; i++) {
        if (i + 1 == columnSize) { query += columnNames[i] + " "; }
        else { query += columnNames[i] + ", "; }
    }

    query += "FROM " + tableName;
    return queryDB(query);
}


// MAIN FUNC
int main()
{
    string columns[] = { "id", "Field", "Header", "randomInt"};
    string insertValues[] = { "13", "html", "test", "74"};
    const int valuesSize = sizeof(insertValues) / sizeof(insertValues[0]);
    const int size = sizeof(columns) / sizeof(columns[0]);
    insertData("tableName", columns, size, insertValues, valuesSize);

    string data = returnValues(columns, "testTable", 4);
    std::cout << "\n" << data;

   //bool isAString = isString("hello1 world");
   //std::cout << isAString;
}

