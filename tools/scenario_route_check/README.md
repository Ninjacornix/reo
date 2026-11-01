This fixture checks the diagnostic chapter selector used by
`REO_TEST_ROUTE=character|gameplay` with `REO_TEST_SCENARIO`.

```
clang++ -std=c++17 -Wall -Wextra -Werror -O2 \
  tools/scenario_route_check/main.cpp -o /tmp/reo-scenario-route-check
/tmp/reo-scenario-route-check
```

The selector accepts one digit, 0 through 4, for File #1's original chapter
order. It requires all five chapters to be available and observes the actual
menu cursor before sending ordinary Left, Right or Cross input. Missing/empty
options retain the existing route. Explicit File #2 chapter selection and
invalid options stop automatic input. It does not write guest RAM or alter
frame timing. The unit fixture covers argument parsing, every cursor/target
combination, and rejection of incomplete lists. It does not prove a room loaded
or that effects rendered correctly; use the route log and game-clock journal
for the former, and a visible gameplay check for the latter.
