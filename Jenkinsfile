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
                sh 'gcc -o calculator calculator.c -lm'
            }
        }

        stage('Test') {
            steps {
                sh './calculator < testcase.txt > output.txt'
        	sh 'cmp -s output.txt expected_output.txt || (echo "Test failed!" && exit 1)'
            }
        }

        stage('Docker Build & Push') {
            steps {
                sh 'docker build -t $DOCKER_IMAGE .'
                withCredentials([string(credentialsId: 'docker-password', variable: 'DOCKER_PASS')]) {
                    sh 'echo $DOCKER_PASS | docker login -u manasmann --password-stdin'
                }
                sh 'docker push $DOCKER_IMAGE'
            }
        }

        stage('Deploy with Ansible') {
            steps {
        	sh '''
        	ansible-playbook -i /etc/ansible/hosts deploy.yml
        	'''
    		}
        }
    }
}

