#include <stdio.h>
#include "hanbaiki.h"

void accept_coin()
{
    printf("Coin accepted!\n");
}

void return_coin()
{
    printf("Coin returned\n");
}

void handle_event(fsm_t *fsm, event_t event)
{
    state_t current = fsm->state;
    state_t next    = transition[current][event];

    effect[current][event](fsm);
    fsm->state = next;
}

int main()
{
    printf("Total: 15 yen\n"
           "We only take 5-yen and 10-yen coins\n");

    fsm_t fsm = { TOTAL_NONE };
    fsm_t *fp = &fsm;
    while (fsm.state < TOTAL_FIFTEEN) {

        printf("Please insert your coin: ");

        event_t event;
        int coin;
        scanf("%d", &coin);

        switch (coin) {
            case 5:
                event = FIVE;
                break;
            case 10:
                event = TEN;
                break;
            default:
                event = OTHER;
                break;
        }

        handle_event(fp, event);
    }

    printf("You've just paid 15 yen, thank you!\n");

    return 0;
}
