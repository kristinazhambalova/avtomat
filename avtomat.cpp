#include <iostream>
using namespace std;

class cashRegister 
{
	private:
		int cashOnHand;

	public:
		cashRegister() {           //кол-во денег в кассе = 500
            cashOnHand = 500;
        } 
		cashRegister(int cashIn) {       //кол-во наличных в кассе на опр сумму
            cashOnHand = cashIn;
        }
		int getCurrentBalance() const {     //возвращает значение cashOnHand
            return cashOnHand;
        }
		void acceptAmount(int amountIn) {   //для получения суммы, внесенной клиентом, и обновления суммы в кассе
            cashOnHand += amountIn;
        } 
};

class dispenerType 
{
	private:
		int numberOfItems;
		int cost;   //cost
	public:
        dispenerType() {   ////устанавливает стоимость и количество предметов в диспенсере по 50 штук
            numberOfItems = 50;
            cost = 50;
        }
        dispenerType(int setNoOfItems, int setCost) {  //устанавливает стоимость и количество предметов в диспенсере на значения, указанные пользователем
            numberOfItems = setNoOfItems;
            cost = setCost;
        }
        int getNoOfItems() const {  //для возврата значения NumberOfItems
            return numberOfItems;
        }
		int getCost() const {  //для возврата значения стоимости
            return cost;
        }  
        void makeSale() {  //для уменьшения количества товаров на 1
            numberOfItems--;
        }
};

void showSelection() {
    cout << "*** МЕНЮ ***\n";
    cout << "1. Конфеты\n";
    cout << "2. Чипсы\n";
    cout << "3. Жвачка\n";
    cout << "4. Печенье\n";
    cout << "Введите номер выбранного товара: ";
}

void sellProduct(dispenerType& productDispenser, cashRegister& cash) {
    int cost = productDispenser.getCost();
    int balance = cash.getCurrentBalance();
    int cashIn;
    if (productDispenser.getNoOfItems() > 0) {
        cout << "Стоимость товара: " << cost << "руб. ";
        cin >> cashIn;
        if (cashIn >= cost) {
            if (balance >= cashIn - cost) {
                productDispenser.makeSale();
                cash.acceptAmount(cost);
                cout << "Ваш товар!\n";
                cout << "Ваша сдача: " << cashIn - cost << "руб.\n";
            }
            else {
                cout << "В автомате нет сдачи :(\nВнесите меньшую сумму.\n";
            }
        }
        else {
            cout << "Недостаточно средств. Внесите большую сумму.\n";
        }
    }
    else {
        cout << "Товара нет в наличии:(\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    cashRegister cash(1000);
    dispenerType sweets(200, 29), chips(50, 120), bubbleGum(100, 35), bisquits(25, 50);

    int choice;
    showSelection();
    cin >> choice;

    switch (choice) {
    case 1:
        sellProduct(sweets, cash);
        break;
    case 2:
        sellProduct(chips, cash);
        break;
    case 3:
        sellProduct(bubbleGum, cash);
        break;
    case 4:
        sellProduct(bisquits, cash);
        break;
    default:
        cout << "Неправильный выбор.\n";
        break;
    }

    return 0;
}
