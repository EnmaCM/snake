std::vector<int> Snake::moveHeadTo(std::string new_direction,int win_limit_x,int win_limit_y){
	std::vector<int> headPos = this->snakeParts[0];
	std::vector<int>newHeadPos;
		 
	if(direction == "UP"){
		if(headPos[0]-1 > 0) {
			newHeadPos = {headPos[0]-1,headPos[1]};
		} else{
			newHeadPos = headPos;
		}
			
	}
    else if( direction == "DOWN"){
		if(headPos[0]+1 < win_limit_y) {
	   		newHeadPos = {headPos[0]+1,headPos[1]};
		} else{
			newHeadPos = headPos;
		}
	}
	else if( direction == "LEFT"){
		if(headPos[1]-1 > 0) { 
			newHeadPos = {headPos[0],headPos[1]-1};
		} else{
			newHeadPos = headPos;
		}
	}
	else if( direction == "RIGHT"){
		if(headPos[1] + 1 < win_limit_x) {
			newHeadPos = {headPos[0],headPos[1]+1};
		}else{
			newHeadPos = headPos;
		}
	} else {
		newHeadPos = headPos;
	}
	return newHeadPos;
}