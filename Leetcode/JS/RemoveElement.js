var strStr = function(haystack, needle) {
    const HayStack = haystack.split("")
    const Needle = needle.split("")
    let NeedleStart = 0;
    let StringAll = ""
    let result = -1;

    for(let i =0; i < HayStack.length; i ++) {
        
        const ElementForNeedle = Needle[NeedleStart];
        const ElementForHayStack = HayStack[i];
        if (ElementForNeedle == ElementForHayStack) {
            
            NeedleStart++;
            StringAll  += ElementForNeedle;
            
            if (StringAll == needle && NeedleStart == Needle.length) {

                console.log("MATCHED AT" , i+1 -Needle.length -1 );
                
            }
        }
      
       
    }
    return result;
};

console.log(strStr("hello","lo"));