/*  
**  Project#0 : Getting to Know the ICS 45C VM
**
**  Author: Byung Ho Lee
**  Student ID#: 60626811
**  Start Date: 1/11/2014
**  Due Date: 1/17/2014 
**  Version: 0.14 
**
**  This program requests 3 data:  first name, last name and e-mail adress to its user.
**  Then prints out template(given massage) with those received data.
**
**  NOTE: Validation is not allowed by instruction. I implemented validation functions, 
**  but validation functions will never be used.   
**
*/

#include <iostream>
#include <string>

// FUNCTION DECLARATION
void setFirstName(std::string& firstName);
void setLastName(std::string& lastName);
void setEmailAddress(std::string& eMail);
void setPersonInfo(std::string& firstName, std::string& lastName, std::string& email) ;
void modifyTemplate(std::string& templateStr, std::string& firstName, std::string& lastName, std::string email) ;
void replaceWord(std::string& templateStr, int start, int range, std::string target, std::string word);
int getPosition(std::string templateStr, std::string keyword);
bool hasMore(std::string templateStr, int start, std::string word);
void showMessage(std::string message);
std::string getTemplate();


// These 3 function will not be used.(Validation is not allowed by the instruction.)
// bool isNumber(const char Character);
// bool isCharacter(const char Character);
// bool isValidEmailAddress(std::string email);

// END OF FUNCTION DECLARTION


// FUNCTION DEFINITION

// This funtions gets first name from User.
void setFirstName(std::string& firstName){
    std::cout << "Input your First Name: ";
    std::getline(std::cin, firstName);
}

// This functions gets first name from user.
void setLastName(std::string& lastName){
    std::cout << "Input your Last Name: ";
    std::getline(std::cin, lastName);
}

// This function gets email from user.
void setEmailAddress(std::string& eMail){
    
    std::cout << "Input your e-mail address: ";
    std::getline(std::cin, eMail);

    /* NOTE: VALIDATION IS NOT ALLOWED, so I commented this code.
    bool isNotValid = true;
    while(isNotValid){
        std::cout << "Input your e-mail address: ";
        std::getline(std::cin, eMail);
        if(isValidEmailAddress(eMail))
            isNotValid = false;
        else
            std::cout << "Invalid e-mail adress. Please input valid one.\n";
    }
    std::cout << std::endl << std::endl;
    */
}

// This function excutes above 3 functions which get user information from user.
void setPersonInfo(std::string& firstName, std::string& lastName, std::string& email) {
   setFirstName(firstName);
   setLastName(lastName);
   setEmailAddress(email);

   std::cout << std::endl << std::endl ; // Intentionally prints 2 empty lines.
}

// It prints given message on the screen
void showMessage(std::string message) {
    std::cout << message;
}

// This function returns general message(I call it template), so it can be modified with Customer's name.
std::string getTemplate() {

    std::string templateStr = "From: Customer Service <customer_service@ics45c.com>\n"
    "To: $FIRST_NAME $LAST_NAME <$EMAIL>\n"
    "Subject: ICS45C appreciates your business!\n\n"
    "Dear $FIRST_NAME $LAST_NAME:\n\n"
    "We are writing today to thank you for your business, and to invite you\n"
    "to contact us if you have any comments and concerns about your recent\n"
    "order.  If so, please email us at customer_service@ics45c.com and we\n"
    "would be delighted to discuss them with you.\n\n\n"
    "Many Thanks,\n\nICS45C Customer Service Team\n";

    return templateStr;
}

// This function modifies given template with given words: firstName, lastName, and email address.  
void modifyTemplate(std::string& templateStr, std::string& firstName, std::string& lastName, std::string email) {

    std::string varFirstName="$FIRST_NAME";
    std::string varLastName="$LAST_NAME";
    std::string varEmail="$EMAIL";

    int lengthOfVarFirstName = varFirstName.length();
    int lengthOfVarLastName = varLastName.length();
    int lengthOfVarEmail = varEmail.length();

    replaceWord(templateStr, getPosition(templateStr, varFirstName), lengthOfVarFirstName, varFirstName, firstName);
    replaceWord(templateStr, getPosition(templateStr, varLastName), lengthOfVarLastName, varLastName, lastName);
    replaceWord(templateStr, getPosition(templateStr, varEmail), lengthOfVarEmail, varEmail, email);
}

// This functions returns index of given word.  
int getPosition(std::string templateStr, std::string keyword) {
    return templateStr.find(keyword); 
}

// This functions replace variables in template with given word.
void replaceWord(std::string& templateStr, int start, int range, std::string target,  std::string word) {
   
    int newStart = start + range;
    
    templateStr.replace(start, range, word);
    
    while(hasMore(templateStr, newStart, target)){
        int location = getPosition(templateStr, target);
        templateStr.replace(location, range, word);
        newStart = newStart + range;
    }
}

// This function checks more given variable is in template or not.
bool hasMore(std::string templateStr, int start, std::string word) {
    int temp = templateStr.find(word, start);
    if(temp == -1){
        return false;
    }else{
        return true;
    }
}

/**
 ** VALIDATION is not ALLOWED by instruction of this project. So, I just commented what I implemented.
 **
 **
// This function checks a given character is a alphabet or not.(WILL NOT BE USED. Validation is not allowed by instruction.)
bool isCharacter(const char Character) {
    return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z') );
}

// This function checks a given  character is digit or not. (WILL NOT BE USED. Validation is not allowed by instruction.)
bool isNumber(const char Character) {
    return ( Character >= '0' && Character <= '9');
}

// This function checks email adress is valid or not. (WILL NOT BE USED. Validations is not allowed by instruction. )
bool isValidEmailAddress(std::string email) {

    if(email.length() == 0) // if empty string
        return false;
    if(!isCharacter(email[0])) // if first letter of email string is not a character
        return false;
    
    int atOffset = -1;  // initialize location of character @
    int dotOffset = -1; // initialize location of character .

    for(int i = 0; i < email.length(); i++) {
        if(email[i] == '@')
            atOffset = i;
        else if(email[i] == '.')
            dotOffset = i;
    }
    
    if( (atOffset == -1) || (dotOffset == -1) ) 
        return false;
    if(atOffset > dotOffset)
        return false;
    if(dotOffset >= email.length()-1)
        return false;
    
    return true;
       
}
*/

// END OF FUNCTION DEFINITION


// MAIN FUNCTION
int main()
{
    // Local variable declartions
    std::string firstName = "";
    std::string lastName = "";
    std::string emailAddress= "";
    
    std::string templateStr = getTemplate(); // Load e-mail template 

    setPersonInfo(firstName, lastName, emailAddress); // get data from users.

    modifyTemplate(templateStr, firstName, lastName, emailAddress);  // modify template with data that was provided by users.
  
    showMessage(templateStr); // print modified template on the screen 

    return 0;
}

