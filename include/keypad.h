#include <string>

class Keypad{
    public:
        Keypad(int size, int start, int end);
        Keypad(const Keypad& k);
        ~Keypad();
        void printPad();
        std::string encrypt(std::string message);
        std::string decrypt(std::string cipher);
        void toFile(std::string filename);
    private:
        int* pad;
        int size;
};