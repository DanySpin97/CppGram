#include <json/json.h>

#include "cppgram/exception.hpp"
#include "cppgram/inline_keyboard.hpp"
#include "cppgram/types/enums.hpp"
#include "cppgram/types/inline_keyboard_button.hpp"

using std::string;
using std::vector;

using cppgram::InlineKeyboard;
using cppgram::InlineKeyboardButton;
using cppgram::InlineKeyboardButtonType;

InlineKeyboard::InlineKeyboard()
    : column( 0 )
    , row( 0 )
{
}

unsigned short
InlineKeyboard::changeRow()
{
    column = 0;
    return row++;
}

bool
InlineKeyboard::addButton( const string &text,
                           const string &data,
                           const InlineKeyboardButtonType &buttonType )
{
    if ( text.empty() || data.empty() )
    {
        throw InlineKeyboardNotValid();
    }

    if ( column == 8 )
    {
        changeRow();
    }

    inline_keyboard["inline_keyboard"][row][column]["text"] = text;

    if ( buttonType == InlineKeyboardButtonType::CallbackData )
    {
        inline_keyboard["inline_keyboard"][row][column]["callback_data"] = data;
    }
    else if ( buttonType == InlineKeyboardButtonType::URL )
    {
        inline_keyboard["inline_keyboard"][row][column]["url"] = data;
    }
    else
    {
        inline_keyboard["inline_keyboard"][row][column]["switch_inline_query"] = data;
    }

    column++;

    return true;
}

bool
InlineKeyboard::addButton( const struct InlineKeyboardButton &newButton )
{
    return addButton( newButton.text, newButton.data, newButton.button_type );
}

bool
InlineKeyboard::addButton( const vector<InlineKeyboardButton> &newButtons )
{
    for ( const InlineKeyboardButton &button : newButtons )
    {
        if ( !addButton( button.text, button.data, button.button_type ) )
        {
            return false;
        }
    }
    return true;
}

void
InlineKeyboard::getKeyboard( std::string &reply_markup, const bool &clearKeyboard )
{
    Json::FastWriter writer;
    reply_markup = writer.write( inline_keyboard );

    if ( clearKeyboard )
    {
        inline_keyboard.clear();
    }
}