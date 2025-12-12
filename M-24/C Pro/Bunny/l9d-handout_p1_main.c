#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_USERS 1000
#define MAX_PORTFOLIO 1000

typedef struct
{
    char name[50];
    float price;
} Stock;

typedef struct
{
    char stock_name[50];
    int shares;
} PortfolioEntry;

typedef struct
{
    char username[50];
    PortfolioEntry portfolio[MAX_PORTFOLIO];
    int portfolio_count;
} User;

Stock stocks[MAX_STOCKS];
User users[MAX_USERS];
int stock_count = 0;
int user_count = 0;

int find_stock(const char *name)
{
    for (int i = 0; i < stock_count; i++)
    {
        if (strcmp(stocks[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int find_user(const char *username)
{
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            return i;
        }
    }
    return -1;
}

int find_portfolio_entry(User *user, const char *stock_name)
{
    for (int i = 0; i < user->portfolio_count; i++)
    {
        if (strcmp(user->portfolio[i].stock_name, stock_name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void add_user(const char *username)
{
    if (find_user(username) != -1)
    {
        printf("User %s already exists.\n", username);
        return;
    }
    strcpy(users[user_count].username, username);
    users[user_count].portfolio_count = 0;
    user_count++;
}

void add_stock(const char *name, float price)
{
    if (find_stock(name) != -1)
    {
        printf("Stock %s already exists.\n", name);
        return;
    }
    strcpy(stocks[stock_count].name, name);
    stocks[stock_count].price = price;
    stock_count++;
}

void list_stocks()
{
    for (int i = 0; i < stock_count; i++)
    {
        printf("Stock: %s, Price: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

void buy_shares(const char *username, const char *stock_name, int shares)
{
    int user_idx = find_user(username);
    int stock_idx = find_stock(stock_name);
    if (user_idx == -1)
    {
        printf("User %s does not exist.\n", username);
        return;
    }
    if (stock_idx == -1)
    {
        printf("Stock %s does not exist.\n", stock_name);
        return;
    }

    User *user = &users[user_idx];
    int portfolio_idx = find_portfolio_entry(user, stock_name);
    if (portfolio_idx == -1)
    {
        strcpy(user->portfolio[user->portfolio_count].stock_name, stock_name);
        user->portfolio[user->portfolio_count].shares = shares;
        user->portfolio_count++;
    }
    else
    {
        user->portfolio[portfolio_idx].shares += shares;
    }
    printf("User %s bought %d shares of %s.\n", username, shares, stock_name);
}

void sell_shares(const char *username, const char *stock_name, int shares)
{
    int user_idx = find_user(username);
    if (user_idx == -1)
    {
        printf("User %s does not exist.\n", username);
        return;
    }

    User *user = &users[user_idx];
    int portfolio_idx = find_portfolio_entry(user, stock_name);
    if (portfolio_idx == -1 || user->portfolio[portfolio_idx].shares < shares)
    {
        printf("User %s does not have enough shares of %s to sell.\n", username, stock_name);
        return;
    }

    user->portfolio[portfolio_idx].shares -= shares;
    if (user->portfolio[portfolio_idx].shares == 0)
    {
        user->portfolio_count--;
        for (int i = portfolio_idx; i < user->portfolio_count; i++)
        {
            user->portfolio[i] = user->portfolio[i + 1];
        }
    }
    printf("User %s sold %d shares of %s.\n", username, shares, stock_name);
}

void view_portfolio(const char *username)
{
    int user_idx = find_user(username);
    if (user_idx == -1)
    {
        printf("User %s does not exist.\n", username);
        return;
    }

    User *user = &users[user_idx];
    printf("Portfolio for %s:\n", username);
    for (int i = 0; i < user->portfolio_count; i++)
    {
        int stock_idx = find_stock(user->portfolio[i].stock_name);
        if (stock_idx != -1)
        {
            float total_value = user->portfolio[i].shares * stocks[stock_idx].price;
            printf("Stock: %s, Shares: %d, Total Value: %.2f\n",
                   user->portfolio[i].stock_name, user->portfolio[i].shares, total_value);
        }
    }
}

void process_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(1);
    }

    char command[50], username[50], stock_name[50];
    int shares;
    float price;

    while (fscanf(file, "%s", command) != EOF)
    {
        if (strcmp(command, "AddUser") == 0)
        {
            fscanf(file, "%s", username);
            add_user(username);
        }
        else if (strcmp(command, "AddStock") == 0)
        {
            fscanf(file, "%s %f", stock_name, &price);
            add_stock(stock_name, price);
        }
        else if (strcmp(command, "List") == 0)
        {
            list_stocks();
        }
        else if (strcmp(command, "Buy") == 0)
        {
            fscanf(file, "%s %s %d", username, stock_name, &shares);
            buy_shares(username, stock_name, shares);
        }
        else if (strcmp(command, "Sell") == 0)
        {
            fscanf(file, "%s %s %d", username, stock_name, &shares);
            sell_shares(username, stock_name, shares);
        }
        else if (strcmp(command, "Portfolio") == 0)
        {
            fscanf(file, "%s", username);
            view_portfolio(username);
        }
    }
    fclose(file);
}

int main()
{
    process_file("file.txt");
    return 0;
}
