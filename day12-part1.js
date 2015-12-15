
var json = require("./input.json");
var sum;
sum = 0;

function getTheSum(json) {
	for (var key in json) {
		if(typeof json[key] == "object") {
			getTheSum(json[key]);
		}
		else {
			if(typeof json[key] == "number") {
				sum += json[key];
			}
		}
	}
}

getTheSum(json);
console.log(sum);