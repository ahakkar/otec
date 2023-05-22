/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T15 Valuuttakurssit
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct array size increment, how many structs to add */
#define INCREMENT 10

/* Struct which contains one currency exchange rate */
struct exchange_rate {
    char currency[4];
    double rate;
};


/* Resizes the rates array */
void resize_rates(
    struct exchange_rate **rates,
    int *max_currencies,
    int increment
) {
    *max_currencies += increment;
    *rates = realloc(*rates, *max_currencies * sizeof(struct exchange_rate));

    if (*rates == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
}


/* Add new rate to the rates array */
void add_rate(
    char *input,
    struct exchange_rate **rates,
    int *num_currencies
) {
    char *token;
    char currency[4];
    double rate;

    /* Split input into tokens */
    token = strtok(input, " ");
    token = strtok(NULL, " ");
    strcpy(currency, token);
    token = strtok(NULL, " ");
    rate = atof(token);

    /* Add new rate to the rates array */
    strcpy((*rates)[*num_currencies].currency, currency);
    (*rates)[*num_currencies].rate = rate;
}


/* Convert currency from rate to EUR */
void convert(
    char *input,
    struct exchange_rate **rates,
    int *num_currencies
) {
    char *token;
    char currency[4];
    double amount;
    double converted_amount;
    int i = 0;

    /* Split input into tokens */
    token = strtok(input, " ");
    token = strtok(NULL, " ");
    amount = atof(token);
    token = strtok(NULL, " ");
    strncpy(currency, token, sizeof(currency) - 1);
    currency[sizeof(currency) - 1] = '\0';

    /* Find the currency from the rates array */
    for (i = 0; i < *num_currencies; i++) {
        if (strcmp(currency, (*rates)[i].currency) == 0) {
            converted_amount = amount * (*rates)[i].rate;
            printf("%.3f %s = %.3f EUR\n", amount, currency, converted_amount);
            break;
        }
    }
}


/* Print all stored exchange rates */
void print_rates(struct exchange_rate **rates) {
    int i = 0;
    int num_currencies = sizeof(**rates) / sizeof(*rates[0]);

    for (i = 0; i < num_currencies; i++) {
        printf("%s %.3f\n", (*rates)[i].currency, (*rates)[i].rate);
    }
}


int main(void)
{
    struct exchange_rate *rates = NULL;
    int num_currencies = 0;
    int max_currencies = 0;
    char input[80];
    char *token;

    
    while (1) {
        /* Resize the rates array if it's out of room */
        if (num_currencies == max_currencies) {
            resize_rates(&rates, &max_currencies, INCREMENT);
        }

        /* Read user input to input variable */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        /* Split input into tokens */
        token = strtok(input, " ");
        if (token != NULL) {
            if (strcmp(token, "kurssi")) {
                add_rate(input, &rates, &num_currencies);
                num_currencies++;
            }
            else if (strcmp(token, "muunna")) {
                convert(input, &rates, &num_currencies);
            }            
            else if (strcmp(token, "kurssit") == 0) {
                print_rates(&rates);
            }
            else if (strcmp(token, "lopeta") == 0) {
                break;
            }
            else {
                printf("Unknown command: %s\n", token);
            }
        }

    }

    free(rates);

    return 0;
}