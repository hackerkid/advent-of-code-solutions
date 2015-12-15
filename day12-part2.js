
var json = require("./input.json");
var sum;
sum = 0;

function check(json, tar)
{	if(json.constructor == Array)
		return false;

	for (var key in json) {
		if(json[key] == tar) {
			return true;
		}
	}

	return false;
}
function getTheSum(json) {
	if(check(json, "red")) {
		return;
	}
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