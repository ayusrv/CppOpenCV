import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.brown,
      ),
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

  @override
  Widget build(BuildContext context) {
    var arrName = ["Ayush", "Himanshu", "Kshitij", "Aman", "Abhishek", "Ved Tanwar", "Akshit", "Satyam", "Lakshay", "Shivam"];
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).primaryColor,
        title: const Text("Title"),
      ),
      body: Center(
        child: ListView.separated(itemBuilder: (context, index) {
          return ListTile(
            leading: const CircleAvatar(
              backgroundImage: AssetImage('assets/images/image.jpg'),
              // radius: 50,
              // you can add child to add widget in this circular image also
              // maxRadius: 30,
            ),
            title: Text(arrName[index], style:const TextStyle(fontFamily: 'FontMain', fontWeight: FontWeight.w100),),
            subtitle: const Text('Number'),
            trailing: const Icon(Icons.add),
          );
        },
          itemCount: arrName.length,
          separatorBuilder: (context, index) {
            return const Divider(height: 20, thickness: 4,);
          },),
      ),
    );
  }
}
// child: ListView(
//   children: const [
//     Padding(
//       padding: EdgeInsets.all(8.0),
//       child: Text('One', style: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
//     ),
//     Padding(
//       padding: EdgeInsets.all(8.0),
//       child: Text('Two', style: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
//     ),
//     Padding(
//       padding: EdgeInsets.all(8.0),
//       child: Text('Three', style: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
//     ),
//     Padding(
//       padding: EdgeInsets.all(8.0),
//       child: Text('Four', style: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
//     ),
//     Padding(
//       padding: EdgeInsets.all(8.0),
//       child: Text('Five', style: TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
//     ),
//   ],
// ),


// child: ListView.builder(itemBuilder: (context, index) {
// return Padding(
// padding: const EdgeInsets.all(10.0),
// child: Text(arrName[index], style:const TextStyle(fontSize: 21, fontWeight: FontWeight.w500),),
// );
// },itemCount: arrName.length,
// itemExtent: 100,