#include "UnrealEnginePythonPrivatePCH.h"



PyObject *py_ue_add_controller_yaw_input(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	float val;
	if (!PyArg_ParseTuple(args, "f:add_controller_yaw_input", &val)) {
		return NULL;
	}

	APawn *pawn = nullptr;

	if (self->ue_object->IsA<APawn>()) {
		pawn = (APawn *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<APawn>()) {
				pawn = (APawn *)actor;
			}
		}
	}

	if (!pawn)
		return PyErr_Format(PyExc_Exception, "uobject is not a pawn");

	pawn->AddControllerYawInput(val);

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_add_controller_pitch_input(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	float val;
	if (!PyArg_ParseTuple(args, "f:add_controller_pitch_input", &val)) {
		return NULL;
	}

	APawn *pawn = nullptr;

	if (self->ue_object->IsA<APawn>()) {
		pawn = (APawn *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<APawn>()) {
				pawn = (APawn *)actor;
			}
		}
	}

	if (!pawn)
		return PyErr_Format(PyExc_Exception, "uobject is not a pawn");

	pawn->AddControllerPitchInput(val);

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_add_movement_input(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	float x, y, z;
	float scale = 1;
	PyObject *py_force = nullptr;
	bool force = false;
	if (!PyArg_ParseTuple(args, "fff|fO:add_movement_input", &x, &y, &z, &scale, &py_force)) {
		return NULL;
	}

	if (py_force && PyObject_IsTrue(py_force)) {
		force = true;
	}

	APawn *pawn = nullptr;

	if (self->ue_object->IsA<APawn>()) {
		pawn = (APawn *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<APawn>()) {
				pawn = (APawn *)actor;
			}
		}
	}

	if (!pawn)
		return PyErr_Format(PyExc_Exception, "uobject is not a pawn");

	pawn->AddMovementInput(FVector(x, y, z), scale, force);

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_get_control_rotation(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	APawn *pawn = nullptr;

	if (self->ue_object->IsA<APawn>()) {
		pawn = (APawn *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<APawn>()) {
				pawn = (APawn *)actor;
			}
		}
	}

	if (!pawn)
		return PyErr_Format(PyExc_Exception, "uobject is not a pawn");

	FRotator rot = pawn->GetControlRotation();
	return Py_BuildValue("fff", rot.Roll, rot.Pitch, rot.Yaw);
}

PyObject *py_ue_jump(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	character->Jump();

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_crouch(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	character->Crouch();

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_stop_jumping(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	character->StopJumping();

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_uncrouch(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	character->UnCrouch();

	Py_INCREF(Py_None);
	return Py_None;
}


PyObject *py_ue_launch(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	float x, y, z;
	PyObject *py_xy_override = nullptr;
	PyObject *py_z_override = nullptr;
	bool xy_override = false;
	bool z_override;
	if (!PyArg_ParseTuple(args, "fff|OO:launch", &x, &y, &z, &py_xy_override, &z_override)) {
		return NULL;
	}

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	if (py_xy_override && PyObject_IsTrue(py_xy_override)) {
		xy_override = true;
	}

	if (py_z_override && PyObject_IsTrue(py_z_override)) {
		z_override = true;
	}

	character->LaunchCharacter(FVector(x, y, z), xy_override, z_override);

	Py_INCREF(Py_None);
	return Py_None;
}

PyObject *py_ue_is_jumping(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	if (character->IsJumpProvidingForce()) {
		Py_INCREF(Py_True);
		return Py_True;
	}

	Py_INCREF(Py_False);
	return Py_False;
}

PyObject *py_ue_is_crouched(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	if (character->bIsCrouched) {
		Py_INCREF(Py_True);
		return Py_True;
	}

	Py_INCREF(Py_False);
	return Py_False;
}

PyObject *py_ue_is_falling(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	UMovementComponent *movement = character->GetMovementComponent();
	if (movement && movement->IsA<UCharacterMovementComponent>()) {
		UCharacterMovementComponent *character_movement = (UCharacterMovementComponent *)movement;
		if (character_movement->IsFalling()) {
			Py_INCREF(Py_True);
			return Py_True;
		}
	}

	Py_INCREF(Py_False);
	return Py_False;
}

PyObject *py_ue_is_flying(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	UMovementComponent *movement = character->GetMovementComponent();
	if (movement && movement->IsA<UCharacterMovementComponent>()) {
		UCharacterMovementComponent *character_movement = (UCharacterMovementComponent *)movement;
		if (character_movement->IsFlying()) {
			Py_INCREF(Py_True);
			return Py_True;
		}
	}

	Py_INCREF(Py_False);
	return Py_False;
}

PyObject *py_ue_can_jump(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	if (character->CanJump()) {
		Py_INCREF(Py_True);
		return Py_True;
	}

	Py_INCREF(Py_False);
	return Py_False;
}

PyObject *py_ue_can_crouch(ue_PyUObject *self, PyObject * args) {

	ue_py_check(self);

	ACharacter *character = nullptr;

	if (self->ue_object->IsA<ACharacter>()) {
		character = (ACharacter *)self->ue_object;
	}
	else if (self->ue_object->IsA<UActorComponent>()) {
		UActorComponent *component = (UActorComponent *)self->ue_object;
		AActor *actor = component->GetOwner();
		if (actor) {
			if (actor->IsA<ACharacter>()) {
				character = (ACharacter *)actor;
			}
		}
	}

	if (!character)
		return PyErr_Format(PyExc_Exception, "uobject is not a character");

	if (character->CanCrouch()) {
		Py_INCREF(Py_True);
		return Py_True;
	}

	Py_INCREF(Py_False);
	return Py_False;
}