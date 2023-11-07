#include <iostream>
#include <cstring>

struct Token {
    char* token;
    int n;
};

class Pyramid {
private:
    Token token;
    char* pyramidShapedTexts;
public:
    Pyramid (): token({nullptr, 0}), pyramidShapedTexts(nullptr) {}
    Pyramid (const Pyramid& _pyramid): token(_pyramid.token), pyramidShapedTexts(_pyramid.pyramidShapedTexts) {}
    Pyramid& operator = (const Pyramid& _pyramid) {
        if (this == &_pyramid) { // if the instance is coming from the same address
            return *this;
        } else {
            delete [] this->token.token;
            delete [] this->pyramidShapedTexts;

            int _pyr_n = _pyramid.token.n;                      
            
            // set token
            this->token.token = new char[_pyr_n];
            strcpy(this->token.token, _pyramid.token.token);

            // set pyramid shaped texts
            this->pyramidShapedTexts = new char[(_pyr_n*_pyr_n)+((_pyr_n-1)*((_pyr_n-1)+1)/2)+(_pyr_n+1)];
            strcpy(this->pyramidShapedTexts, _pyramid.pyramidShapedTexts);

            // set n of token
            this->token.n = _pyr_n;

            return *this;
        }
    }

    void setToken(const char* _token, const int _n) {

        // set token
        this->token.token = new char[_n+1];
        strcpy(this->token.token, _token);

        // set pyramid shaped texts
        this->pyramidShapedTexts = new char[(_n*_n)+((_n-1)*((_n-1)+1)/2)+(_n+1)];
        std::cout << "length: " << (_n*_n)+((_n-1)*((_n-1)+1)/2)+(_n+1) << "\n";
        
        int row, col;
        int pyramidShapedTextsIndex = 0;

        int index = 1;
        for (row=0; row<_n; ++row) {

            int tokenIndex = 0;

            for (col=0; col<_n+row; ++col) {
                
                if (col >= (_n-1-row)) {
                    if (col < (_n-1-row) + row) {
                        std::cout << "i-: " << index << ", [" << row << "," << col << "]" << ": " << token.token[tokenIndex] << "\n";
                        index++;

                        pyramidShapedTexts[pyramidShapedTextsIndex] = this->token.token[tokenIndex++];
                    } else {
                        std::cout << "i-: " << index << ", [" << row << "," << col << "]" << ": " << token.token[tokenIndex] << "\n";
                        index++;

                        pyramidShapedTexts[pyramidShapedTextsIndex] = this->token.token[tokenIndex--];
                    }
                } else {
                    std::cout << "i-: " << index << ", [" << row << "," << col << "]" << ": " << " " << "\n";
                    index++;

                    pyramidShapedTexts[pyramidShapedTextsIndex] = ' ';
                }
                pyramidShapedTextsIndex++;
            }
            std::cout << "i-: " << index << ", [" << row << "," << col << "]" << ": " << "CR" << "\n";
            index++;

            pyramidShapedTexts[pyramidShapedTextsIndex] = '\n';
            pyramidShapedTextsIndex++;
        }
        std::cout << "i-: " << index << ", [" << row << "," << col << "]" << ": " << "NULL" << "\n";
        pyramidShapedTexts[pyramidShapedTextsIndex] = '\0';

        // set n of token
        this->token.n = _n;
    }

    ~Pyramid() {
        delete [] token.token;
        delete [] pyramidShapedTexts;
    }

    operator char* () const {
        return this->pyramidShapedTexts;
    }
};

int main(int argc, char* argv[]) {

    // create Pyramid instance/object
    Pyramid pyramid;

    // set Pyramid instance/object data members
    const char token[] = {"ABCDE"};
    const int n = strlen(token);
    pyramid.setToken(token, n);

    // display pyramid
    std::cout << pyramid;

    return 0;
}