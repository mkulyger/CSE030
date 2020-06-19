$(document).ready(function(){
    
  $("#button").click(function(){
    var amount = $("#center").val();

  $.get("/Press", {"amount": number}, function(response){
      $("answer").html(response);
    
  });
    });

     
});
