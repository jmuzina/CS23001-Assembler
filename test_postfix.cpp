/**
 * Joseph Muzina
 * Assembler
 * CS 23001
 */

#include "utilities.hpp"
#include "stack.hpp"
#include "../string/string.hpp"
#include <iostream>

int main() {
    {
        String infix("( ( ( ( AB / C ) + D ) - ( E * F ) ) );");
        String result = infix_to_postfix(infix);
        String answer("AB C / D + E F * -");
        assert(result == answer);
    }
    {
        String infix("( ( ( ( ( A + ( B * C ) ) - ( D / ( E * F ) ) ) + G ) / ( ( H - ( I * J ) ) * ( KLMN + O ) ) ) );");
        String result = infix_to_postfix(infix);
        String answer("A B C * + D E F * / - G + H I J * - KLMN O + * /");
        assert(result == answer);
    }
    {
        String infix("( ( ( ( ( ( ( ( A * B ) + C ) - D ) / ( E * F ) ) - GH ) * ( I / J ) ) / K ) );");
        String result = infix_to_postfix(infix);
        String answer("A B * C + D - E F * / GH - I J / * K /");
        assert(result == answer);
    }
    std::cout << "[UNIT TEST]: Infix->Postfix conversion test ran successfully\n";
    return 0;
}
