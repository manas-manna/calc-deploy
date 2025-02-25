pipeline {
    agent any

    environment {
        DOCKER_IMAGE = "manasmann/scientific-calculator:v1"
    }

    stages {
        stage('Checkout Code') {
            steps {
                git branch: 'main', url: 'https://github.com/manas-manna/calc-deploy'
            }
        }

        stage('Build') {
            steps {
                sh 'gcc -o calculator scientific_calculator.c -lm'
            }
        }

        stage('Test') {
            steps {
                sh './calculator'  // Add test cases here if needed
            }
        }

        stage('Docker Build & Push') {
            steps {
                sh 'docker build -t $DOCKER_IMAGE .'
                sh 'docker login -u manasmann -p passkey'
                sh 'docker push $DOCKER_IMAGE'
            }
        }

        stage('Deploy with Ansible') {
            steps {
                sh 'ansible-playbook -i /etc/ansible/hosts deploy.yml'
            }
        }
    }
}
