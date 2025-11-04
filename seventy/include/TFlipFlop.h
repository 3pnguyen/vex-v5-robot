#ifndef TFLIPFLOP_H
#define TFLIPFLOP_H

class TFlipFlop {
    private:
        bool state;

    public:
        TFlipFlop(bool initial_state = false);
        void clock_edge(bool T_input);
        bool get_state() const;
        bool get_inverted_state() const;
};

#endif