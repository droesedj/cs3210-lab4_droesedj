################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../circle.cpp \
../gcontext.cpp \
../line.cpp \
../main.cpp \
../matrix.cpp \
../point.cpp \
../shape.cpp \
../x11context.cpp 

OBJS += \
./circle.o \
./gcontext.o \
./line.o \
./main.o \
./matrix.o \
./point.o \
./shape.o \
./x11context.o 

CPP_DEPS += \
./circle.d \
./gcontext.d \
./line.d \
./main.d \
./matrix.d \
./point.d \
./shape.d \
./x11context.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


