#ifndef SECRET_HOLDER_H
#define SECRET_HOLDER_H

/*
 This is the header file for the SecretHolder class. It contains all the attributes that are to be used as well as the method declarations. The definitions for the methods can be seen in the file SecretHolder.cpp
 */
namespace SH
{
    class SecretHolder
    {
        private:
            // Attributes
            int _secretCode[4];
            int _complexity; // this represents the number of different numbers that could be occupying each spot
            int _redPins;
            int _whitePins;

            // Private Methods
            void GenerateCode();
        
        public:
            // Constructor
            SecretHolder();

            // Public Methods
            void SetComplexity(int c);
            void SetResults(int guess);
            int GetRedPins();
            int GetWhitePins();
            void DisplayCode();
            
    };
}

#endif // SECRET_HOLDER_H
