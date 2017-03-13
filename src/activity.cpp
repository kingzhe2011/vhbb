#include "activity.h"

Activity::~Activity()
{

}


int Activity::HandleInput(int focus, const Input& input)
{
    if (views_.size() > 1) {
        for (auto it = begin(views_), it_last = --end(views_); it != it_last; ++it) {
            it->HandleInput(0, input);
        }
    } else if (views_.size() == 0) {
        return 0;
    }

    views_.back().HandleInput(1, input);
}


int Activity::Display()
{
    if (views_.empty()) return 0;

    for (auto it = begin(views_), it_last = end(views_); it != it_last; ++it) {
        it->Display();
    }
}


void Activity::AddView(View &view)
{
    views_.push_back(view);
}

bool Activity::HasActivity()
{
    return !views_.empty();
}