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

/* Compare function for sorting exchange rates by currency */
int compare_rates(const void *a, const void *b);


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
    char *currency,
    double rate,
    struct exchange_rate **rates,
    int *num_currencies,
    int *max_currencies
) {
    int i = 0;
    /* printf("Amount of added currencies: %d\n", *num_currencies); */
    /* Resize the rates array if it's out of room */
    if (*num_currencies == *max_currencies) {
        resize_rates(rates, max_currencies, INCREMENT);
    }

    /* Check if the currency is already in the rates array and update it */
    for (i = 0; i < *num_currencies; i++) {
        if (strcmp(currency, (*rates)[i].currency) == 0) {
            (*rates)[i].rate = rate;
            return;
        }
    }

    /* Otherwise add new rate to the rates array */
    strcpy((*rates)[*num_currencies].currency, currency);
    (*rates)[*num_currencies].rate = rate;
    (*num_currencies)++;
    /* printf("Added currency %s with rate %.3f\n", currency, rate); */
}


/* Convert currency from rate to EUR */
void convert(
    double rate,
    char *currency,
    struct exchange_rate **rates,
    int *num_currencies
) {
    double converted_amount;
    int i = 0;

    /* Find the currency from the rates array */
    for (i = 0; i < *num_currencies; i++) {
        if (strcmp(currency, (*rates)[i].currency) == 0) {
            converted_amount = rate / (*rates)[i].rate;
            printf("%.3f %s = %.3f EUR\n", rate, currency, converted_amount);
            return;
        }
    }

    printf("Valuutan %s kurssia ei ole tiedossa!\n", currency);
}


int compare_rates(const void *a, const void *b) {
    const struct exchange_rate *rate_a = (const struct exchange_rate *)a;
    const struct exchange_rate *rate_b = (const struct exchange_rate *)b;

    return strcmp(rate_a->currency, rate_b->currency);
}


/* Print all stored exchange rates */
void print_rates(struct exchange_rate **rates, int *num_currencies) {
    int i = 0;

    /* Sort the rates array by currency */
    qsort(*rates, *num_currencies, sizeof(struct exchange_rate), compare_rates);

    for (i = 0; i < *num_currencies; i++) {
        printf("%s %.3f\n", (*rates)[i].currency, (*rates)[i].rate);
    }
}




int main(void)
{
    struct exchange_rate *rates = NULL;
    int num_currencies = 0;
    int max_currencies = INCREMENT;
    char input[80];
    char *token;
    char currency[4];
    double rate;

    /* Initialize the rates array */
    rates = malloc(max_currencies * sizeof(struct exchange_rate));
    if (rates == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    
    while (1) {
        /* Read user input to input variable */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue;
        }

        /* Split input into tokens */
        token = strtok(input, " ");
        if (token != NULL) {
            if (strcmp(token, "kurssi") == 0) {
                token = strtok(NULL, " ");
                strncpy(currency, token, sizeof(currency) - 1);
                currency[sizeof(currency) - 1] = '\0';
                token = strtok(NULL, " ");
                rate = atof(token); 

                add_rate(currency, rate, &rates, &num_currencies, &max_currencies);   
            }
            else if (strcmp(token, "muunna") == 0) {
                token = strtok(NULL, " ");
                rate = atof(token);
                token = strtok(NULL, " ");
                strncpy(currency, token, sizeof(currency) - 1);
                currency[sizeof(currency) - 1] = '\0';

                convert(rate, currency, &rates, &num_currencies);
            }            
            else if (strcmp(token, "kurssit\n") == 0) {
                print_rates(&rates, &num_currencies);
            }
            else if (strcmp(token, "lopeta\n") == 0) {
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