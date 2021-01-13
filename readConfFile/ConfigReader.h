//
// Created by bmondal on 09.09.20.
//

#ifndef READCONFFILE_CONFIGREADER_H
#define READCONFFILE_CONFIGREADER_H

// C++ Header File(s)
#include <iostream>
#include <map>

// Define namespace for this class. so that anyonelo
// can easily integrate it. The class name is vary generic
// so the chance to collapse the class name is high.
// So need to define the class inside the namespace.

namespace cppsecrets
{
    // Defining ConfigReader as singleton class
    // Easy to access across the multiple classes
    //
    // The responsibility of this class is to parse the
    // Config file and store it in the std::map
    // Defined getter function getValue() to get the
    // data from the std::map.
    //
    // To use this class, pass the config file path to
    // the function getInstance()
    //
    // This is one of the advance config reader, because this
    // class is handling the comment line as well. Comment line
    // will start from hash(#). So all the string after
    // semicolon will be discarded.
    //
    // NOTE: NO NEED TO MAKE THIS CLASS THREAD-SAFE. IT IS EXTRA OVEHEAD.
    // BECAUSE MOSTLY WE ARE DOING ONLY READ OPERATION. WRITE OPERATION IS
    // HAPPENING ONLY ONE TIME, WHICH IS IN THE FUNCTION parse(). SO CALL
    // parse() FUNCTION AT THE TIME OF INITIALIZATION ONLY.
    //
    // IF YOUR CONFIGURATION FILE IS UPDATING AT THE RUN TIME AND YOU NEED
    // UPDATED DATA FROM THE CONFIGURATION FILE AT RUN TIME, THEN YOU NEED
    // TO MAKE THIS CLASS THREAD-SAFE.

    class ConfigReader
    {
    private:

        // Define the map to store data from the config file
        std::map<std::string, std::string> m_ConfigSettingMap;

        // Static pointer instance to make this class singleton.
        static ConfigReader* m_pInstance;

    public:

        // Public static method getInstance(). This function is
        // responsible for object creation.
        static ConfigReader* getInstance();

        // Parse the config file.
        bool parseFile(const std::string& fileName = "/home/bmondal/CLionProjects/readConfFile/default_config");
        //bool parseFile(const std::string& fileName = "/home/bmondal/CLionProjects/readConfFile/cutfile_reco_a_dilep.txt");

        // Overloaded getValue() function.
        // Value of the tag in cofiguration file could be
        // string or integer. So the caller need to take care this.
        // Caller need to call appropiate function based on the
        // data type of the value of the tag.

        bool getValue(const std::string& tag, int& value);
        bool getValue(const std::string& tag, std::string& value);

        // Function dumpFileValues is for only debug purpose
        void dumpFileValues();

    private:

        // Define constructor in the private section to make this
        // class as singleton.
        ConfigReader();

        // Define destructor in private section, so no one can delete
        // the instance of this class.
        ~ConfigReader();

        // Define copy constructor in the private section, so that no one can
        // voilate the singleton policy of this class
        ConfigReader(const ConfigReader& obj){}

        // Define assignment operator in the private section, so that no one can
        // voilate the singleton policy of this class
        void operator=(const ConfigReader& obj){}

        // Helper function to trim the tag and value. These helper function is
        // calling to trim the un-necessary spaces.
        static std::string trim(const std::string& str, const std::string& whitespace = " \t");
        static std::string reduce(const std::string& str,
                           const std::string& fill = " ",
                           const std::string& whitespace = " \t");
    };

} //End of namespace


#endif //READCONFFILE_CONFIGREADER_H
