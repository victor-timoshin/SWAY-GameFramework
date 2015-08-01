#ifndef SINGLETON_H
#define SINGLETON_H

namespace Utils
{
	template<typename TYPE> class TSingleton
	{
	public:
		/// <summary>Конструктор класса.</summary>
		TSingleton(void)
		{
			instance = static_cast<TYPE*>(this);
		}

		/// <summary>Деструктор класса.</summary>
		~TSingleton(void)
		{
			instance = nullptr;
		}

		static TYPE& GetInstance(void)
		{
			return *instance;
		}

		static TYPE* GetInstancePtr(void)
		{
			return instance;
		}
	protected:
		static TYPE* instance;
	};

	template<typename TYPE>TYPE* TSingleton<TYPE>::instance = nullptr;
}

#endif // SINGLETON_H