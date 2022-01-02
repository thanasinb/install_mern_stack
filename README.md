# Installing VS Code
[from https://dev.to/rohidhub/top-10-vscode-extensions-for-react-57g6]

## EXTENSIONS
Auto Rename Tag<br>
Bracket Pair Colorizer<br>
ES7 React/Redux/GraphQL/React-Native snippets<br>
Prettier - Code formatter<br>
indent-rainbow<br>
VSCode React Refactor<br>
npm Intellisense<br>
ESLint<br>
Highlight Matching Tag<br>
TabOut<br>
GitLens<br>
Git History<br>
DotENV<br>
Better comments<br>

## Connect VS Code to Ubuntu Multipass
Install VS Code extension: Remote - SSH<br>

[from https://dev.to/josuebustos/vs-code-remote-ssh-multipass-dn8]<br>
Create an SSH key and copy it into `/<user>/.ssh/authorized_keys`<br>
This way we can login to our Ubuntu Multipass using `ssh ubuntu@<ip address>`<br>
We can find the IP from `multipass list`<br>


# Integrating MQTT with NodeJS
## Installing MQTT broker (Mosquitto)
[from https://thanapontapala.medium.com/mqtt-%E0%B8%A5%E0%B8%AD%E0%B8%87-mqtt-%E0%B8%9A%E0%B8%99-nodejs-%E0%B9%80%E0%B8%96%E0%B8%AD%E0%B8%B0%E0%B8%84%E0%B8%A3%E0%B8%B1%E0%B8%9A-217a682e18e7]
[from http://www.steves-internet-guide.com/using-node-mqtt-client/]
```
 sudo apt-get install mosquitto -y
 sudo apt-get install mosquitto-clients -y
```

In order to check Mosquitto is running
```
sudo systemctl status mosquitto
```

Simple test by publishing "hello world" via "test" topic, terminal 1 should see the message
```
mosquitto_sub -h localhost -t test //terminal 1
mosquitto_pub -h localhost -t test -m "hello world" //terminal 2
```

## Mosquitto - NodeJS integration
Create a NodeJS project directory, within the directory, install the MQTT package for the NodeJS
```
npm install mqtt --save
```

Test the system by creating a js file at the project directory.
Then, copy and paste the code in the following link into the file: https://gist.github.com/toygame/5c7aab9bf63ca271ba330da7230934fe#file-mqtt-js and run
```
node [file.js]
```
This code will publish `hello from NodeJS` to the `test` channel every 5s

## Adding user accounts into the Mosquitto
[from https://www.arubacloud.com/tutorial/how-to-install-and-secure-mosquitto-on-ubuntu-20-04.aspx]

To apply user account to Mosquitto, we need to add a user by
```
sudo mosquitto_passwd -c /etc/mosquitto/passwd [user]
```
This will prompt a password for the specified user

Then, create the file: `default.conf`
```
sudo nano /etc/mosquitto/conf.d/default.conf
```
And paste the follwing script
```
allow_anonymous false
password_file /etc/mosquitto/passwd
```
Finally, restart Mosquitto using
```
sudo systemctl restart mosquitto
```
To test the configuration, modify the `MQTT_USER` and `MQTT_PASSWORD` in the above js file and run it again

## Preparing ESP8266 for MQTT comm
[from https://toomtamdn.medium.com/nodemcu-esp8266-%E0%B8%AA%E0%B9%88%E0%B8%87%E0%B8%82%E0%B9%89%E0%B8%AD%E0%B8%A1%E0%B8%B9%E0%B8%A5%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%99-mqtt-8366aaa27e32]
In Arduino IDE, add PubSubClient library by clicking
```
Menu -> Sketch -> Include Library -> Manage Libraries…
```
Search for `PubSubClient` which is contributed by Nick O'Leary and install it


# Installing MongoDB

[from https://www.howtoforge.com/how-to-install-mern-stack-for-js-based-applications-on-debian-11/]<br>
```
sudo apt-get update -y
```

[from https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/]<br>
```
wget -qO - https://www.mongodb.org/static/pgp/server-5.0.asc | sudo apt-key add -
```

[for Ubuntu 20.04 (Focal)]<br>
```
echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/5.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-5.0.list
sudo apt-get update -y
sudo apt-get install -y mongodb-org
sudo systemctl start mongod
sudo systemctl enable mongod
sudo systemctl status mongod
mongod --version

mongo
use admin
db.createUser({user: "admin" , pwd: passwordPrompt() , roles: [{ role: "userAdminAnyDatabase" , db: "admin"}]})
quit()
```

# Installing NodeJS
[from https://github.com/nodesource/distributions]
```
curl -fsSL https://deb.nodesource.com/setup_16.x | sudo -E bash -
sudo apt-get install -y nodejs
node --version
```

# Installing React.JS
[continue https://www.howtoforge.com/how-to-install-mern-stack-for-js-based-applications-on-debian-11/]<br>
[continue https://dev.to/andrewbaisden/creating-mern-stack-applications-2020-4a44]
[https://blog.logrocket.com/mern-stack-tutorial/]
[https://codedec.com/tutorials/how-to-setup-express-server-to-develop-mern-application/]

