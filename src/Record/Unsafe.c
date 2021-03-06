#include <purescript.h>

PURS_FFI_FUNC_2(Record_Unsafe_unsafeHas, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key);
	const purs_record_t * val = purs_record_find_by_key(rec, key_);
	if (val != NULL) {
		return purs_any_true;
	} else {
		return purs_any_false;
	}
});

PURS_FFI_FUNC_2(Record_Unsafe_unsafeGet, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key);
	const purs_record_t * val = purs_record_find_by_key(rec, key_);
	if (val != NULL) {
		return val->value;
	} else {
		return (const purs_any_t *) NULL;
	}
});

PURS_FFI_FUNC_3(Record_Unsafe_unsafeSet, key, value, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_copy = purs_string_copy(purs_any_get_string(key));
	return purs_any_record_new(purs_record_add(rec, key_copy, value));
});

PURS_FFI_FUNC_2(Record_Unsafe_unsafeDelete, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key);
	return purs_any_record_new(purs_record_remove(rec, key_));
});
