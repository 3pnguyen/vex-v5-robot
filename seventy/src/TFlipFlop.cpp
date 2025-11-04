#include "TFlipFlop.h"

TFlipFlop::TFlipFlop(bool initial_state) : state(initial_state) {}

void TFlipFlop::clock_edge(bool T_input) {
    if (T_input) state = !state;
}

bool TFlipFlop::get_state() const {
    return state;
}

bool TFlipFlop::get_inverted_state() const {
    return !state;
}