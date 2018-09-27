
function Openregister(){
	document.getElementById('login').classList.add("slideOutLeft");
	setTimeout(()=>{
		document.getElementById("login").style.display = "none";
	},300);
	document.getElementById('register').style.display = "block";

}

	function status(message){
		Toastify({
			text: "<i class='fa fa-check-circle'></i> "+message,
			duration: 5000,
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
      duration: 8000,
      newWindow: true,
      close: true,
      gravity: "top", // `top` or `bottom`
      positionRight: true, // `true` or `false`
      backgroundColor: "linear-gradient(to right, #dd1818, #ff8c00)",
      }).showToast();
  }

function authChk() {
	return true;
}


function Openlogin() {
	location.reload();
}


function login() {
	if(authChk() == true){
		document.getElementById('login').classList.add("flipOutX");
	setTimeout(()=>{
		document.getElementById("login").style.display = "none";
		document.getElementById('app').style.display = "block";
		status("Successfully Logged In");
		document.body.classList.add("vertical-scroll")
	},700);

	}
}

function wdraw(){
  swal({
		html: `
		    <div class="p2">
		    <h2><i class="fa fa-minus-circle btn btn-just-icon btn-round nav-red"></i> Withdrawal</h2>
		    <br>
			    <div class="p-2 nav-red rounded">
			       <span class="text-white pt-1"><i class="fa fa-circle text-warning"></i> Current Balance</span>
			       <h3 class="text-white">₱ 12,000</h3>
			    </div>  
           			    <br>
           		   <input class="mt-1 p-2 rounded border" placeholder="Amount to Withdraw" id="wvalue">   
             </div>`,
        showCancelButton: true,     
    }).then((res)=>{
        if(res){
           var Withdrawal_value = document.getElementById("wvalue").value;
              if(Withdrawal_value){
                 swal({
                 	title: "Transaction Complete",
                 	type: "success",
                 	text: "You withdrawed ₱ "+Withdrawal_value+" from your account",
                 	showCancelButton: false,
                 	showConfirmButton: false,
                 	timer: 2000
                 }) 	
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
			       <h3 class="text-white">₱ 12,000</h3>
			    </div>  
           			    <br>
           		   <input class="mt-1 p-2 rounded border" placeholder="Amount to Withdraw" id="wvalue">   
             </div>`,
        showCancelButton: true,     
    }).then((res)=>{
        if(res){
           var Withdrawal_value = document.getElementById("wvalue").value;
              if(Withdrawal_value){
                 swal({
                 	title: "Transaction Complete",
                 	type: "success",
                 	text: "You Deposited ₱ "+Withdrawal_value+" from your account",
                 	showCancelButton: false,
                 	showConfirmButton: false,
                 	timer: 2000
                 }) 	
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
	var accountName = document.getElementById("accName");
	var ppin = document.getElementById("ppin");
  var cppin = document.getElementById("cppin");
	   if(accountName.value && ppin.value && cppin.value){
        if(cppin.value == ppin.value){
           swal({
           	 html: `
                 <h3>Account Created!</h3>
                 <p class="small"><strong>Take note of the login details of your account, do not share it with anyone</strong></p>
                  <div class="p-3 bg-green rounded" style="text-align:left">
			       <span class="text-white pt-1 mx-3"><i class="fa fa-circle text-info"></i> Account Details</span>
			       <hr>
			       <ul class="p-0" style="list-style:none;">
			            <li class="text-white">Account Name: `+accountName.value+`</li>
				       <li class="text-white">Account Number: 11-22-33</li>
				       <li class="text-white">PIN: `+ppin.value+`</li>
			       </ul>

			    </div>
           	 `,
           	 type: 'success',
           })
         }else{
            error("Error: pins you typed did not match!");
         }
	   }else{
	   	 error("Error: Please complete the form before submitting");
	   }
}