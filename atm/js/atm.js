
window.onload = function() {
  document.getElementById("accNum").focus();
}

function Openregister(){
	document.getElementById('login').classList.add("slideOutLeft");
	setTimeout(()=>{
		document.getElementById("login").style.display = "none";
	},300);
	document.getElementById('register').style.display = "block";

}

const formatPrice = (n) => {
  var parts = n.toString().split(".");
  parts[0] = parts[0].replace(/\B(?=(\d{3})+(?!\d))/g, ",");
  return parts.join(".");
}


	function status(message){
		Toastify({
			text: "<i class='fa fa-check-circle'></i> "+message,
			duration: 3000,
			newWindow: true,
			close: true,
			gravity: "top", // `top` or `bottom`
			positionRight: true, // `true` or `false`
			backgroundColor: "linear-gradient(to right, #00b09b, #96c93d)",
      }).showToast();
	}

	function error(message){
    Toastify({
      text: "<i class='fa fa-times-circle'></i> "+message,
      duration: 3000,
      newWindow: true,
      close: true,
      gravity: "top", // `top` or `bottom`
      positionRight: true, // `true` or `false`
      backgroundColor: "linear-gradient(to right, #dd1818, #ff8c00)",
      }).showToast();
  }

function authChk() {
    var accNum = document.getElementById("accNum"); 
    var pin = document.getElementById("pin");
  	  axios.get("atm.cgi?accNum="+accNum.value+"~null~"+pin.value+"~login")
          .then((res)=>{
             var data = res.data.split(",");
               if(data.length == 4){
                  localStorage.auth = true;
                  localStorage.userName = decodeURIComponent(data[1]); 
                  localStorage.accNum = data[2];
                  localStorage.Balance = data[3];
                  logSetup();
               }else{
                error(data);
               }
          });
}


function Openlogin() {
	location.reload();
}


function login() {
  authChk();
}

function tcolor(transaction){
   var t = transaction.toLowerCase();
      if(t == "deposit"){
         return "text-success";
      }else{
        return "text-danger";
      }
}

function calendar(){
  var today = new Date();
var dd = today.getDate();
var mm = today.getMonth()+1; //January is 0!
var yyyy = today.getFullYear();

    if(dd<10) {
        dd = '0'+dd
    } 

    if(mm<10) {
        mm = '0'+mm
    } 

    today = mm + '-' + dd + '-' + yyyy;
    return today;
}

function logSetup(){
   document.getElementById('login').classList.add("flipOutX");
  setTimeout(()=>{
    document.getElementById("login").style.display = "none";
    document.getElementById('app').style.display = "block";
    status("Successfully Logged In");  
    document.body.classList.add("vertical-scroll")
    // document.body.style.height = "100%";

    // parse values

     // set welcome
     document.getElementById("firstName").innerText = localStorage.userName.split(" ")[0];
    //get balance
    document.getElementById("accbal").innerText = formatPrice(localStorage.Balance);
    // set name 
    document.getElementById("uname").innerText = localStorage.userName;
    // set acc num.
    document.getElementById("accnum1").innerText = localStorage.accNum;
    // set list of transactions 
    axios.get("./accounts/"+localStorage.accNum+"_balance_records")
     .then((res)=>{
       if(res.data){
           var data = res.data.split("\n");
             for(var i=data.length; i--;){
               if(data[i]){
                var details = data[i].split(",");
                    document.getElementById("tlog").innerHTML += `
                      <td><strong class="`+tcolor(details[0])+`" style="text-transform: capitalize;">`+details[0]+`</strong></td>
                        <td>&#x20b1; `+formatPrice(details[1])+`</td>
                        <td>&#x20b1; `+formatPrice(details[2])+`</td>
                        <td>&#x20b1; `+formatPrice(details[3])+`</td>
                        <td>`+details[4]+`</td>
                      </tr>
                    `;
                  }
             }
       }else{
         document.getElementById("tlog").innerHTML = "<h3 class='text-none'><i class='fa fa-file-text-o'> Nothing to show..</h3>";
       }
     });

  },700);
}

function wdraw(){
  swal({
		html: `
		    <div class="p2">
		    <h2><i class="fa fa-minus-circle btn btn-just-icon btn-round nav-red"></i> Withdrawal</h2>
		    <br>
			    <div class="p-2 nav-red rounded">
			       <span class="text-white pt-1"><i class="fa fa-circle text-warning"></i> Current Balance</span>
			       <h3 class="text-white">&#x20b1; `+formatPrice(localStorage.Balance)+`</h3>
			    </div>  
           			    <br>
           		   <input class="mt-1 p-2 rounded border" placeholder="Amount to Withdraw" id="wvalue">   
             </div>`,
        showCancelButton: true,     
    }).then((res)=>{
        if(res){
           var Withdrawal_value = document.getElementById("wvalue").value;
           if(Withdrawal_value){

            if(parseInt(Withdrawal_value) > parseInt(localStorage.Balance)){
              error("Insufficent Funds!");
              return false;
            }
           var balVal = parseInt(localStorage.Balance) - parseInt(Withdrawal_value);
           axios("atm.cgi?accNum="+localStorage.accNum+"~null~null~transact~"+localStorage.Balance+"~"+Withdrawal_value+"~"+balVal+"~withdraw~"+calendar())
             .then((res)=>{
              if(res.data){
              
                 swal({
                 	title: "Transaction Complete",
                 	type: "success",
                 	text: "You withdrew "+formatPrice(Withdrawal_value)+" from your account",
                 	showCancelButton: false,
                 	showConfirmButton: false,
                 	timer: 3000
                 }) 	
                 setTimeout(()=>{
                 window.location.reload();
               },2500);
               }
         
          });
            }else{
              error("Error: no specified amout, Transaction Cancelled");
           }
          }
    })         
   }


function deposit(){
	swal({
		html: `
		    <div class="p2">
		    <h2><i class="fa fa-plus-circle btn btn-just-icon btn-round btn-success"></i> Deposit</h2>
		    <br>
			    <div class="p-2 bg-green rounded">
			       <span class="text-white pt-1"><i class="fa fa-circle text-info"></i> Current Balance</span>
			       <h3 class="text-white">&#x20b1; `+formatPrice(localStorage.Balance)+`</h3>
			    </div>  
           			    <br>
           		   <input class="mt-1 p-2 rounded border" placeholder="Amount to Withdraw" id="wvalue">   
             </div>`,
        showCancelButton: true,     
    }).then((res)=>{
         if(res){
           var Withdrawal_value = document.getElementById("wvalue").value;
           if(Withdrawal_value){
           var balVal = parseInt(localStorage.Balance) + parseInt(Withdrawal_value);
           axios("atm.cgi?accNum="+localStorage.accNum+"~null~null~transact~"+localStorage.Balance+"~"+Withdrawal_value+"~"+balVal+"~deposit~"+calendar())
             .then((res)=>{
              if(res.data){
              
                 swal({
                  title: "Transaction Complete",
                  type: "success",
                  text: "You deposited "+formatPrice(Withdrawal_value)+" from your account",
                  showCancelButton: false,
                  showConfirmButton: false,
                  timer: 3000
                 })   
               }
                setTimeout(()=>{
                 window.location.reload();
               },2500);
         
          });
            }else{
              error("Error: no specified amout, Transaction Cancelled");
           }
          }
    })
}

function cpin(){
		swal({
		html: `
		    <div class="p2">
		    <h2><i class="fa fa-plus-circle btn btn-just-icon btn-round btn-warning"></i> Change Pin</h2>
		        <span class="my-2 small">Make sure you set a Completely new pin to complete the Transaction</span>
		        <br>
		        <br>
			    <input type="password" class="mt-1 p-2 rounded border btn-span" placeholder="Enter Old pin" id="oldpin">   
           			    <br>
           		   <input type="password" class="mt-1 p-2 rounded border btn-span" placeholder="Enter New Pin" id="npinx">   
             </div>`,
        showCancelButton: true,     
    }).then((res)=>{
        if(res){	
           var opin = document.getElementById("oldpin");
           var npin = document.getElementById("npinx");
             if(opin.value && npinx.value){
              if(opin.value != npinx.value){
                // pin change validation via axios;
                   swal("Success","you have Successfully changed your pin","success");
           }else{
           	  error("Error: your new pin and old pin are the same, aborted pin change.");
           }
          }else{
          	 error("Error: form wasn't filled correctly, aborted pin change")
          }
        }
    })
}

function register() {
  var accountNum = document.getElementById("raccNum");
	var accountName = document.getElementById("accName");
	var ppin = document.getElementById("ppin");
  var cppin = document.getElementById("cppin");
	   if(accountNum.value && accountName.value && ppin.value && cppin.value){
        if(cppin.value == ppin.value){

          axios.get("atm.cgi?accNum="+accountNum.value+"~"+accountName.value+"~"+ppin.value+"~register")
          .then((res)=>{
          if(res.data.length != 29){
           swal({
           	 html: `
                 <h3>Account Created!</h3>
                 <p class="small"><strong>Take note of the login details of your account, do not share it with anyone</strong></p>
                  <div class="p-3 bg-green rounded" style="text-align:left">
			       <span class="text-white pt-1 mx-3"><i class="fa fa-circle text-info"></i> Account Details</span>
			       <hr>
			       <ul class="p-0" style="list-style:none;">
			            <li class="text-white">Account Name: `+accountName.value+`</li>
				       <li class="text-white">Account Number: `+accountNum.value+`</li>
				       <li class="text-white">PIN: `+ppin.value+`</li>
			       </ul>
			    </div>
           	 `,
           	 type: 'success',
           })
          }else{
            error(res.data);
          }
         });
         }else{
            error("Error: pins you typed did not match!");
         }
	   }else{
	   	 error("Error: Please complete the form before submitting");
	   }
}