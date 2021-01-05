#ifndef HANBAIKI_H
#define HANBAIKI_H

#define NUM_STATE 5
#define NUM_EVENT 3

typedef enum {
    FIVE,   /* inserted a 5-yen coin */
    TEN,    /* inserted a 10-yen coin */
    OTHER   /* other coins that will be returned by the machine */
} event_t;

typedef enum { /* the total value of the coins you've inserted so far */
    TOTAL_NONE,
    TOTAL_FIVE,
    TOTAL_TEN,
    TOTAL_FIFTEEN,
    TOTAL_OVER
} state_t;

typedef struct fsm {
    state_t state;
    /* more data can be added here */
} fsm_t;

typedef void (*action_t) (fsm_t *);

void handle_event(fsm_t *fsm, event_t event);
void accept_coin();
void return_coin();

state_t const transition[NUM_STATE][NUM_EVENT] = {
  //  5              10             others       states/events
     {TOTAL_FIVE,    TOTAL_TEN,     TOTAL_NONE },     // OTHER 
     {TOTAL_TEN,     TOTAL_FIFTEEN, TOTAL_FIVE },     // FIVE
     {TOTAL_FIFTEEN, TOTAL_OVER,    TOTAL_TEN  }      // TEN
};

action_t const effect[NUM_STATE][NUM_EVENT] = {
    //5            10           others       states/events
     {accept_coin, accept_coin, return_coin},      // OTHER
     {accept_coin, accept_coin, return_coin},      // FIVE
     {accept_coin, accept_coin, return_coin}       // TEN
};

#endif
