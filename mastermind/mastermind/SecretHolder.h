#ifndef SECRET_HOLDER_H
#define SECRET_HOLDER_H

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
