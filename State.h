//
// Created by meni on 17/01/2020.
//

#ifndef MILE_STONE2__STATE_H_
#define MILE_STONE2__STATE_H_
template <class T>
class State {
 private :
  T _state; // the state represented by string
  double _cost // cost to reach this state
  State<T> _cameFrom; //the state we came from to this state
  public:
  State(State<T> state) {
    this->_state = state;
    this->_cameFrom = nullptr;
  };
  bool Equals(State<T> s) {
    return this->_state.Eqals(s._state);
  }
  bool isValid(State<T> s)
};
#endif //MILE_STONE2__STATE_H_
