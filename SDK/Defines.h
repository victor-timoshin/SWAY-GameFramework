#ifndef DEFINES_H
#define DEFINES_H

#define OR  || // Логическая операция ИЛИ.
#define AND && // Логическая операция И.
#define NOT !  // Логическая операция НЕ.

#ifdef BUILDING_CORE
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

#ifndef __FUNCTION_NAME__
	#ifdef WIN32
		#define __FUNCTION_NAME__ __FUNCTION__
	#else
		#define __FUNCTION_NAME__ __func__
	#endif
#endif

#define SAFE_RELEASE(x) if(x != nullptr) { x->Release(); x = nullptr; }
#define SAFE_DELETE(x) if(x != nullptr) { delete x; x = nullptr; }
#define SAFE_DELETE_ARRAY(x) if(x != nullptr) { delete[] x; x = nullptr; }

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define CASE_VALUE_TOSTRING(x) case x: return #x

#define SOURCE_LOCATION __FILE__ ":" TOSTRING(__LINE__)

#define DECL_VAR(type, location) \
	public: \
		type location;

#define DECL_PROPERTY_SET(prefix, type, name) public: void prefix##name(type value);
#define DECL_PROPERTY_GET(prefix, type, name) public: type prefix##name(void) const;

#define DECL_PROPERTY(type, name, location) \
		DECL_PROPERTY_SET(##Set, type, name) \
		DECL_PROPERTY_GET(##Get, type, name) \
		DECL_VAR(type, location)

#define DECL_PROPERTY_STRING(name, location) DECL_PROPERTY(std::string, name, location)
#define DECL_PROPERTY_FLOAT(name, location) DECL_PROPERTY(float, name, location)
#define DECL_PROPERTY_DOUBLE(name, location) DECL_PROPERTY(double, name, location)
#define DECL_PROPERTY_INT(name, location) DECL_PROPERTY(int, name, location)
#define DECL_PROPERTY_BOOLEAN(name, location) \
		DECL_PROPERTY_SET(##Use, bool, name) \
		DECL_PROPERTY_GET(##Has, bool, name) \
		DECL_VAR(bool, location)

#define DECL_PROPERTY_VIRTUAL_SET(prefix, type, name) public: virtual void prefix##name(type value);
#define DECL_PROPERTY_VIRTUAL_GET(prefix, type, name) public: virtual type prefix##name(void) const;

#define DECL_PROPERTY_VIRTUAL(type, name, location) \
		DECL_PROPERTY_VIRTUAL_SET(##Set, type, name) \
		DECL_PROPERTY_VIRTUAL_GET(##Get, type, name) \
		DECL_VAR(type, location)

#define DECL_PROPERTY_VIRTUAL_STRING(name, location) DECL_PROPERTY_VIRTUAL(std::string, name, location)
#define DECL_PROPERTY_VIRTUAL_FLOAT(name, location) DECL_PROPERTY_VIRTUAL(float, name, location)

#define DECL_PROPERTY_STATIC(type, name, location) \
		DECL_VAR(type, location) \
	public: \
		static void Set##name(type value); \
		static type Get##name(void);

#define DECL_PROPERTY_INLINE_SET(prefix, type, name, location) public: void prefix##name(type value) { location = value; }
#define DECL_PROPERTY_INLINE_GET(prefix, type, name, location) public: type prefix##name(void) const { return location; }

#define DECL_PROPERTY_INLINE(type, name, location) \
		DECL_PROPERTY_INLINE_SET(##Set, type, name, location) \
		DECL_PROPERTY_INLINE_GET(##Get, type, name, location) \
		DECL_VAR(type, location)

#define DECL_PROPERTY_INLINE_FLOAT(name, location) DECL_PROPERTY_INLINE(float, name, location)
#define DECL_PROPERTY_INLINE_BOOLEAN(name, location) \
		DECL_PROPERTY_INLINE_SET(##Use, bool, name, location) \
		DECL_PROPERTY_INLINE_GET(##Has, bool, name, location) \
		DECL_VAR(bool, location)

#define DEF_PROPERTY_SET(thisClass, prefix, type, name, location) void thisClass :: prefix##name(type value) { location = value; }
#define DEF_PROPERTY_GET(thisClass, prefix, type, name, location) type thisClass :: prefix##name(void) const { return location; }

#define DEF_PROPERTY(thisClass, type, name, location) \
		DEF_PROPERTY_SET(thisClass, ##Set, type, name, location)  \
		DEF_PROPERTY_GET(thisClass, ##Get, type, name, location)

#define DEF_PROPERTY_STRING(thisClass, name, location) DEF_PROPERTY(thisClass, std::string, name, location)
#define DEF_PROPERTY_FLOAT(thisClass, name, location) DEF_PROPERTY(thisClass, float, name, location)
#define DEF_PROPERTY_INT(thisClass, name, location) DEF_PROPERTY(thisClass, int, name, location)
#define DEF_PROPERTY_INT(thisClass, name, location) DEF_PROPERTY(thisClass, int, name, location)
#define DEF_PROPERTY_BOOLEAN(thisClass, name, location) \
		DEF_PROPERTY_SET(thisClass, ##Use, bool, name, location) \
		DEF_PROPERTY_GET(thisClass, ##Has, bool, name, location)

#endif // DEFINES_H