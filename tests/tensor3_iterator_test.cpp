#include "tensor3_iterator_test.hpp"

#include <vmmlib/tensor3_iterator.hpp>
#include <vmmlib/tensor3.hpp>

#include <sstream>

namespace vmml
{
	
	bool
	tensor3_iterator_test::run()
	{
		bool ok = false;
		
		tensor3< 2, 3, 4, uint16_t >  t3;
		
		t3.fill_increasing_values();
		
        typedef tensor3< 2, 3, 4, uint16_t >    myt3;
		
		myt3::iterator it = t3.begin(), it_end = t3.end();
        
        std::vector< uint16_t > t3_iter_order;
        std::vector< uint16_t > hand_iter_order;
        
		
		
		for( ; it != it_end; ++it )
		{
            t3_iter_order.push_back( *it );
		}
        
        for( size_t index = 0; index < 4; ++index )
        {
            matrix< 2, 3, uint16_t >& m = t3.get_frontal_slice( index );
            
            tensor3< 2, 3, 4, uint16_t >::matrix_iterator 
                it      = m.begin(),
                it_end  = m.end();
            for( ; it != it_end; ++it )
            {
                hand_iter_order.push_back( *it );
            }
        }
        
        ok = t3_iter_order == hand_iter_order;
        
		log( "tensor3 iterator  ", ok  );

		
		ok = true;
		return ok;
	}
	
	
} // namespace vmml