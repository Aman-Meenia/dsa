function validateEmailMessage(email) {
  var pattern = /.{1,}@.{1,}/;
  return pattern.test(email);
}

console.log(validateEmailMessage(" @  "));
