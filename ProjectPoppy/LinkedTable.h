#pragma once

template<class T>
class LinkedTable {
public:
	LinkedTable() {}

	struct element {
		element() {}
		element(T v) : val(v) {}
		element* next = nullptr;
		T val;
	}*start = nullptr;

	void AddValue(T val) {
		if (start == nullptr) { start = new element(val); return; }
		
		element* i = start;
		while (i != nullptr) { // somewhat un-needed but just incase :P
			if (i->next == nullptr) break;
			i = i->next;
		}
		i->next = new element(val);
	}

	void RemoveValue(int index) {
		element* i = start;
		while (i != nullptr) {
			if (index == 1) { // next value is value to be erased
				if (i->next != nullptr) // just a check
					i->next = i->next->next; // skip next value
			}
			if (i->next == nullptr) break;
			i = i->next;
			index--;
		}
	}

	T getValue(int index) {
		element* i = start;
		while (i != nullptr) {
			if (index == 0) { // at the correct value
				return i->val;
			}
			if (i->next == nullptr) break;
			i = i->next;
			index--;
		}
	}

	int count() {
		int ret = (start == nullptr) ? 0 : 1;

		element* i = start;
		while (i != nullptr) {
			if (i->next == nullptr) break;
			i = i->next;
			ret++;
		}

		return ret;
	}
};