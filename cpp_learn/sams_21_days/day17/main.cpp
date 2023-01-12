/*
 * Day 17: Working with streams
 * -------------------------------
 *
 * - iostream library handles input and output
 * - streambuf class manages buffer : fill, empty, flush
 * - ios class: has streambuf object as member variable. base class for input and output stream classes
 * - istream and ostream : derive from ios class and specialize input and output respectively
 * - iostream derives from istream and ostream and provides methods to write to screen
 * - fstream : provides input and output from files
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

struct sensorModuleData
{
    float temp;
    float humidity;
    float pressure;
    uint64_t tstamps[10];
    string tag_name;
}typedef sensorModuleData;

/*
 * Function writes a sequence of characters to the specified file
 */
void writeToTextFile(const char* fileName, const char* text)
{
    ofstream writeHandle(fileName, ios::app);
    if(!writeHandle)
    {
        cout << "File opening failed.." << endl;
    }

    else
    {
        writeHandle << text;
        writeHandle.close();
    }
}

/*
 * Function reads and displays contents of a text file till EOF is encountered
 */
void readFromTextFile(const char* fileName)
{
    ifstream readHandle(fileName);
    if (!readHandle)
        cout << "File opening failed for read..." << endl;
    else
    {
        char ch;
        while (readHandle.get(ch))
        {
            cout << ch;
        }
        //
        readHandle.close();
    }
}

/*
 * Function writes a complex data object as binary data to file
 */
void writeBinaryToFile(const char* fileName, sensorModuleData& sensorData)
{
    ofstream writeHandleBinary(fileName, ios::app | ios::binary); // ORing multiple flags
    if (!writeHandleBinary)
        cout << "File open failed for write..." << endl;
    else
    {
        writeHandleBinary.write((char*) &sensorData, sizeof sensorData); //  expects char pointer
        writeHandleBinary.close();
        cout << "Written..." << endl;
    }
}

/*
 * Function reads a binary file and saves to a complex data type
 */
void readBinaryFromFile(const char* fileName, sensorModuleData& sensorData)
{
    ifstream readHandle(fileName, ios::binary);
    if (!readHandle)
        cout << "File opening failed for read..." << endl;
    else
    {
        readHandle.read((char*) &sensorData, sizeof sensorData);
        readHandle.close();
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    //
    char message[1024];

    cout << "Enter your message: " << endl;
    cin.get(message, 1024, '+'); // reads upto 1024 chars from console including spaces and new line, stops when + encountered

    cout << message << endl;

    cin.getline(message, 1024); // similar behaviour as cin.get but terminating char is \n by default. Also term char is not saved in the buffer

    writeToTextFile("test.txt", "Hello, my name is Sambit");
    readFromTextFile("test.txt");
    //
    sensorModuleData sens1, sens2;
    sens1.temp = 23.45;
    sens1.humidity = 67.90;
    sens1.tag_name = "xx1sd";
    sens1.tstamps[0] = 109863;
    sens1.tstamps[1] = 908343;
    writeBinaryToFile("sens.dat", sens1);
    readBinaryFromFile("sens.dat", sens2);
    return 0;
}
