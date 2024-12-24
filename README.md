# 🐄🐑🐔 Farm Market System 🛠️

This project was developed as part of my **Advanced Programming** course at Ben-Gurion University. It simulates a **Farm Market System** where farmers manage farms, trade goods, and buy livestock. The system emphasizes the use of **C++** features and implements design patterns for efficient operation.

---

## ✨ Features

- 🏠 **Farm Management:** Create and manage farms specializing in cows, sheep, or chickens.
- 💸 **Trading System:** Farmers buy and sell goods based on their farm type.
- 🐾 **Livestock Management:** Purchase animals with distinct characteristics (age, lifespan, and productivity).
- 📊 **Observer Pattern:** Efficient notification system for trade participants.
- 🔄 **Yearly Progression:** Simulate yearly operations with changes in farm resources, animal aging, and revenue updates.

---

## ⚙️ Prerequisites

To run this project, ensure you have the following installed:

- ✅ GCC or any compatible C++ compiler
- ✅ Make utility for compilation

---

## 🖍️ Usage Instructions

1. Compile the project using the provided `makefile`:

   ```bash
   make
   ```

   This will create an executable named `CPP_FARM`.

2. Run the program:

   ```bash
   ./CPP_FARM
   ```

3. Use the interactive menu to:

   - Add new farms.
   - Trade goods between farms.
   - Buy livestock for farms.
   - Fast-forward years to simulate farm progression.

---

## ⚖️ File Structure

- `Farm.h/cpp`: Farm class implementation.
- `Market.h/cpp`: Market class handling trade and year progression.
- `Animal.h/cpp`: Animal class with shared attributes for cows, sheep, and chickens.
- `FarmMarket.h/cpp`: Main interface for running the system.
- `Makefile`: Builds the project and generates the executable.

---

## 🔍 Additional Notes

- **Error Handling:** The program includes custom exceptions for invalid inputs, such as negative values for farm quantities.
- **Memory Management:** Ensures dynamic memory allocation is handled efficiently.
- **Design Patterns:** Implements the Observer design pattern for managing trade notifications.

---

## 🐾 Example Scenarios

1. **Farm Creation:**

   - Add farms for cows, sheep, or chickens.
   - Each farm starts with a default balance and no animals.

2. **Trading:**

   - Farmers trade goods:
     - Cow farms buy eggs.
     - Sheep farms buy milk.
     - Chicken farms buy wool.

3. **Yearly Progression:**

   - Animals age, produce goods, and farms earn revenue.
   - Old animals are removed, and new ones can be purchased.

4. **Error Handling:**

   - Attempting to add negative farms raises exceptions like:
     ```text
     Cow exception: Cannot add a negative number of cow farms.
     ```

---

## 🦾 Example Menu

```text
Welcome to the Farm Market System!
1. Add Farms
2. Start Trading
3. Buy Animals
4. Print Farm Details
5. Fast Forward Years
6. Exit
```

Feel free to explore, trade, and expand your farms! 🌾🚜

---

