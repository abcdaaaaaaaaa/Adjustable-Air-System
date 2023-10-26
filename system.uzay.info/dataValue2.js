        $(document).ready(function() {
            function getData() {
                var url ="https://api.thingspeak.com/channels/2195036/fields/1,2,3,4,5,6,7,8.json?api_key=DG5Q1OBE0MW2GDTF&results=1";

                $.getJSON(url, function(data) {
                    var field1Values = [];
                    var field2Values = [];
                    var field3Values = [];
                    var field4Values = [];
                    var field5Values = [];
                    var field6Values = [];	
                    var field7Values = [];	
                    var field8Values = [];	
                    var timestamps = [];

                    $.each(data.feeds, function(index, feed) {
						field1Values.push(feed.field1);
						field2Values.push(feed.field2);
						field3Values.push(feed.field3);
						field4Values.push(feed.field4);
						field5Values.push(feed.field5);
						field6Values.push(feed.field6);
						field7Values.push(feed.field7);
						field8Values.push(feed.field8);
						timestamps.push(feed.created_at);
					});
        
const toplam9 =  parseInt(field1Values);   
const toplam10 = parseInt(field2Values);   
const toplam11 = parseInt(field3Values)/Math.pow(10, 6);    
const toplam12 = parseInt(field4Values)/Math.pow(10, 6); 


   
document.cookie = "value9="+toplam9;
document.cookie = "value10="+toplam10;
document.cookie = "value11="+toplam11;
document.cookie = "value12="+toplam12;

console.log(toplam9);
console.log(toplam10);
console.log(toplam11);
console.log(toplam12);


                });


            }
            getData();

        });