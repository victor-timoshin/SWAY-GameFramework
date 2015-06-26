#ifndef SINGLETON_H
#define SINGLETON_H

namespace Utils
{
	template<typename TYPE> class TSingleton
	{
	public:
		/** Constructor. */
		TSingleton()
		{
			instance = static_cast<TYPE*>(this);
		}

		/** Destructor. */
		~TSingleton()
		{
			instance = 0L;
		}

		static TYPE& GetInstance()
		{
			return *instance;
		}

		static TYPE* GetInstancePtr()
		{
			return instance;
		}
	protected:
		static TYPE* instance;
	};

	template<typename TYPE>TYPE* TSingleton<TYPE>::instance = 0L;
}

#endif // SINGLETON_H