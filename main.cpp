/* Alexander Mendez 11-26-20
	Dr_T COSC 1437-58003
	Unit 5 - Vectors, Functions, Conditions, Loops, Color, and Sorting Values
	repl.it 
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std; 

class MenuItem
{
	private:
		string name;
		double itemCost; 
		string desc; 
		char addLetter; 
		char removeLetter;
		int count;
	public:
		void setName(string);
		void setItemCost(double);
		void setDesc(string); 
		void setAddLetter(char); 
		void setRemoveLetter(char);
		void setCount(int);
		string getName() const;
		double getItemCost() const; 
		string getDesc() const; 
		char getAddLetter() const; 
		char getRemoveLetter() const;
		int getCount() const;
};
		//setters
		void MenuItem::setName(string n){ name = n; }	
		void MenuItem::setItemCost(double ic)	{itemCost = ic; }
		void MenuItem::setDesc(string d)	{	desc = d;	}
		void MenuItem::setAddLetter(char a)	{	addLetter = a; }
		void MenuItem::setRemoveLetter(char r) {	removeLetter = r;	}
		void MenuItem::setCount(int c) { count = c;}
		// getters
		string MenuItem::getName() const { return name; }
		double MenuItem::getItemCost() const { return itemCost; }
		string MenuItem::getDesc() const { return desc; } 
		char MenuItem::getAddLetter() const { return addLetter; } 
		char MenuItem::getRemoveLetter() const { return removeLetter; }
		int MenuItem::getCount() const { return count; }




//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Water", "Pizza", "Wings", "Pasta", "Calzone", "Pretzels"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setCount(0); //initialze all counts to 0
  }
		// set item prices
    entireMenu[0].setItemCost(3.00); //set a random starter cost for each item
		entireMenu[1].setItemCost(1.00);
		entireMenu[2].setItemCost(7.00);
		entireMenu[3].setItemCost(5.00);
		entireMenu[4].setItemCost(8.00);
		entireMenu[5].setItemCost(10.00);
		entireMenu[6].setItemCost(2.50);
		// set item descriptions
		entireMenu[0].setDesc("Dr.T's Signature Green Tea"); 
		entireMenu[1].setDesc("Natural Spring Water"); 
		entireMenu[2].setDesc("Large 3 Topping Pizza"); 
		entireMenu[3].setDesc("8 Piece Wings"); 
		entireMenu[4].setDesc("Shrimp Alfredo"); 
		entireMenu[5].setDesc("It's like a pizza sandwich"); 
		entireMenu[6].setDesc("Giant Pretzels with Dipping Sauce"); 
}


void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "Class Style Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ") " << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << "\t" << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0;
	double total = 0.0;
	double tax = 0.065;
	double tip = 0.0;
	double temp = 0.0;
	double tender = 0.0;
	double changeBack = 0.0;
	string input = "";

  do
  {
    cout << "\nPlease choose an item (x to Continue to Checkout): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(m[i].getCount()+1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(m[i].getCount()-1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(option != m[i].getAddLetter() && option != m[i].getRemoveLetter() && option != 'x' && option != 'X' ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
	cout << "Would you like to tip? Y/N: ";
	cin >> option;
	if(option == 'Y' || option == 'y')
	{
		cout << "Enter your tip. We suggest 20% or more. 20% = $" << (subtotal * .2) << endl;
		cout << ": ";
		cin >> tip;
		// new total
	}
	else if(option == 'N' || option == 'n')
	{
		cout << "Continue to payment" << endl;
	}
	else
	{
		cout << "\nInvalid input (" << option << "). Please try again." << endl;
	}


	// cash or card
	cout << "Cash or Card: ";
	cin >> input;

	if((input == "Cash") || (input == "cash") || (input == "CASH"))
	{
		temp = (subtotal * tax) + tip;  
		total = subtotal + temp;
		cout << "Your total is: " << total << endl;

		cout << "Please enter the amount you would like to pay with: ";
		cin >> tender;

		if(tender >= total)
		{
			changeBack = tender - total;
			cout << "\nYour change is: " << changeBack;
		}
	}
	else if((input == "Card") || (input == "card") || (input == "CARD"))
	{
		temp = (subtotal * tax) + tip; 
		total = subtotal + temp;

		cout << "Your total is: " << total << endl;
		cout << "Proccessing payment: " << endl;
	}
	else
	{
		cout << "\nInvalid input (" << option << "). Please try again." << endl;
	}

//handle reciept generation here
	cout << "\n\n______________________RECIEPT______________________" << endl;
	
	for(int i=0; i < m.size(); i++)
	{
		if( m[i].getCount() > 0)
		{
			cout << m[i].getCount() << "\t" << m[i].getName() << "\t" << (m[i].getItemCost() * m[i].getCount()) << endl;
		}
	}
	cout << "\nSUBTOTAL: " << subtotal << endl;
	cout << "TIP: " << tip << endl;
	cout << "TAX: " << (tax * subtotal) << endl; 
	cout << "TOTAL: " << total << endl;
	cout << "THANK YOU!" << endl;
}


int main() 
{
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
  
  return 0; 
}