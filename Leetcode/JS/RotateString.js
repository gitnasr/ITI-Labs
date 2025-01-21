var rotateString = function(s, goal) {
    const sAsArray = s.split("");
    const goalAsArray= goal.split("")

    const MapOfChar = new Map()
    if (sAsArray.length != goalAsArray.length ) {
        return false;
    }
    for(var i =0; i < sAsArray.length; i++){
        MapOfChar[sAsArray[i]] = goalAsArray.find(c => c == sAsArray[i])
    }

   for (let index = 0; index < MapOfChar.values().length; index++) {
    const element = array[index];
    if (!element) return false
   }
    return true
};

console.log(rotateString("abcde","cdeab"));
