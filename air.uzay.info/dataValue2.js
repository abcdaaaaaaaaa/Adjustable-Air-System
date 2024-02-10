        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195036/fields/1,2,3,4,5,6,7,8.json?api_key=DG5Q1OBE0MW2GDTF&results=1";

                $.getJSON(url, function(data) {
                    var field5Values = [];
                    var field6Values = [];	
                    var field7Values = [];	
                    var field8Values = [];	
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field5Values.push(feed.field5);
						field6Values.push(feed.field6);
						field7Values.push(feed.field7);
						field8Values.push(feed.field8);
						timestamps.push(feed.created_at);
					});

const toplam13 = parseInt(field5Values);    
const toplam14 = parseInt(field6Values);   
const toplam15 = parseInt(field7Values)/Math.pow(10, 6);   
const toplam16 = parseInt(field8Values)/Math.pow(10, 6);   

document.cookie = "value13="+toplam13;
document.cookie = "value14="+toplam14;
document.cookie = "value15="+toplam15;
document.cookie = "value16="+toplam16;

console.log(toplam13);
console.log(toplam14);
console.log(toplam15);
console.log(toplam16);

                });


            }
            getData();

        });