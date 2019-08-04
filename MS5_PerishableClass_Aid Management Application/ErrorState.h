/* NAME- Youngeun Hong
SENECA ID- 159100171
E-MAIL- yhong38@myseneca.ca
SBB
Date 2019-04-07
*/

#ifndef ama_ERRORSTATE_H_
#define ama_ERRORSTATE_H_

#include <iostream>

namespace ama {

	class ErrorState {

		char * msg;

	public:		
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;
	};
	
	std::ostream& operator << (std::ostream& os, const ErrorState&);

}

#endif

