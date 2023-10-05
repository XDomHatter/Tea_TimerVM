//
// Created by XDomHatter on 2023-08-20.
//

#ifndef $TEA_SRC_SHARE_OOP_BINARY_NAME_HPP
#define $TEA_SRC_SHARE_OOP_BINARY_NAME_HPP

#include <utilities/Tio.hpp>
#include <utilities/types.hpp>

class BinaryName {
public:
    /// Returns the corresponding enum constant
    static TeaType parse_binary_name(char* str) {
        switch (str[0]) {
            case '1':
                return TType_N1;
            case '2':
                return TType_N2;
            case '4':
                return TType_N4;
            case '8':
                return TType_N8;
            case 'L':
                return TType_OOP;
            case '[':
                return TType_ARR;
            case 'S':
                return TType_STR;
        }
        return (TeaType) -1;
    }
    /// Count single binary names
    static tuint count(char *binn) {
        tuint res = 0;
        for(int i = 0; binn[i] != '\0'; i++) {
            switch (binn[i]) {
                case 'L':
                    do{}while(binn[++i] != ';');
                    res++;
                    break;
                case '[':
                    // array, do nothing, the result is appended at the next_binn loop.
                    break;
                case 'U': // C String constant
                case 'M': // Multiple type
                case '1':
                case '2':
                case '4':
                case '8':
                    // normal case
                    res++;
                    break;
                default:
                    TConsole::output_f("tea.lang.ByteCodeError: Unknown character in binary name: %c", binn[i]);
                    break;
            }
        }
        return res;
    }
    /// Return the next binary name
    /// @note It doesn't copy the source string
    static char *next_binn(char *_binn) {
        char *binn = _binn;
        switch (*binn) {
            case 'L':
                do{}while(*(++binn) != ';'); // move to binary name character until it is ';'
                break;
            case '[':
                do{}while(*(++binn) == '['); // move to binary name character until it is not '['
                next_binn(binn); // next binary name is element type
                break;

            case 'S': // C String constant
            case 'M': // Multiple type
            case '1':
            case '2':
            case '4':
            case '8':
                // normal case
                binn++;
                break;

            default:
                TConsole::output_f("tea.lang.ByteCodeError: Unknown character in binary name: %c", *binn);
                break;
        }
        return binn;
    }
    static bool is_basic(char *_binn) {
        TeaType t = parse_binary_name(_binn);
        return !(t == TType_OOP || t == TType_ARR);
    }
};

#endif //$TEA_SRC_SHARE_OOP_BINARY_NAME_HPP
