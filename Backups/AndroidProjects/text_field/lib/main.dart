import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      home: MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  var emailText = TextEditingController();
  var passwordText = TextEditingController();
  var phoneText = TextEditingController();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Text Filed'),
      ),
      body: Center(
          child: Container(
            width: 300,
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Padding(
                    padding: const EdgeInsets.all(10.0),
                    child: TextField(
                      controller: emailText,

                      decoration: InputDecoration(
                        hintText: 'Enter Email',
                        focusedBorder: OutlineInputBorder(
                            borderRadius: BorderRadius.circular(21),
                          borderSide:const BorderSide(
                            color: Colors.orange,
                            width: 2
                          )
                        ),
                        enabledBorder: OutlineInputBorder(
                          borderRadius: BorderRadius.circular(21),
                          borderSide: const BorderSide(
                            color: Colors.blueGrey
                          )
                        ),
                        disabledBorder: OutlineInputBorder(
                            borderRadius: BorderRadius.circular(21),
                            borderSide: const BorderSide(
                                color: Colors.greenAccent
                            ),
                        ),
                        // suffixText: 'UsernameExits',
                        prefixIcon:const Icon(Icons.email, color: Colors.orange,)
                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(10.0),
                    child: TextField(
                      controller: phoneText,
                      keyboardType: TextInputType.phone,
                      obscureText: true, //This will hide the password
                      obscuringCharacter: '&', //This will replace the password with this character while hidden
                      decoration: InputDecoration(
                        hintText: 'Enter Password',
                        prefixIcon: const Icon(Icons.phone),
                        border: OutlineInputBorder(
                            borderRadius: BorderRadius.circular(21),
                            borderSide: const BorderSide(
                                color: Colors.blueGrey
                            )
                        ),

                      ),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(10.0),
                    child: TextField(
                      controller: passwordText,
                      obscureText: true, //This will hide the password
                      obscuringCharacter: '&', //This will replace the password with this character while hidden
                      decoration: InputDecoration(
                        hintText: 'Enter Password',
                        prefixIcon: const Icon(Icons.password_sharp),
                        suffixIcon: IconButton(icon: const Icon(Icons.remove_red_eye, color: Colors.purple,),
                          onPressed: (){

                          },),
                        border: OutlineInputBorder(
                            borderRadius: BorderRadius.circular(21),
                            borderSide: const BorderSide(
                                color: Colors.blueGrey
                            )
                        ),

                      ),
                    ),
                  ),
                  ElevatedButton(onPressed: (){
                    String uName = emailText.text.toString();
                    String uPass = passwordText.text;
                    String uNumber = phoneText.text;
                    if (kDebugMode) {
                      print('Email $uName, Pass $uPass, Phone $uNumber');
                    }
                  }, child: const Text('Login'))
                ],
              )
          ),
      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
