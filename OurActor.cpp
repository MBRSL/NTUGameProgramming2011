#include "OurAction.h"
#include "OurActor.h"
#include "function.h"
#include "AllData.h"

//OurActControl
OurActor::OurActor()
{

}

void OurActor::ourPlayAction()
{
	FnActor actor;
	actor.Object( aID );
	
	if(::actorChangePose( aID, current_OurAction->actID ))
	{
		current_frame = 0;
	}
	//it's a loop action?
	if( current_OurAction->type == Action_type::ACTION_IDLE() ||
		current_OurAction->type == Action_type::ACTION_WALK() )
	{
		actor.Play(0, LOOP, current_OurAction->play_speed, false, true);
		current_frame += current_OurAction->play_speed;
	}
	else
	{
		bool notOver;
		notOver = actor.Play(0, ONCE, current_OurAction->play_speed, false, true);
		if( !notOver )
		{
			if( current_OurAction->type.value != Action_type::ACTION_DIE() )
				current_OurAction = ourIdleAction;
		}
		else
			current_frame += current_OurAction->play_speed;
	}

	playActionAudio();
	playActionFx();
}

bool OurActor::sendAction( OurAction* action )
{
	if( action->priority < current_OurAction->priority )
		return false;
	current_OurAction = action;
	return true;
}

OurAction* OurActor::getCurrentAction()
{
	return current_OurAction;
}

OurFrame* OurActor::getKeyFrame()
{
	if(current_OurAction->keyFrames > 0)
	{
		for( int i=0 ; i < current_OurAction->numOfKeyFrames ; i++ )
		{
			if( current_OurAction->keyFrames[i]->frameNO <= current_frame && 
				current_OurAction->keyFrames[i]->frameNO >= current_frame - current_OurAction->play_speed )
				return current_OurAction->keyFrames[i];
		}
	}
	return NULL;
}

float OurActor::getCurrentFrame()
{
	return current_frame;
}

bool OurActor::playActionAudio()
{
	if( current_OurAction->numOfAudioFrames > 0 )
	{
		FnAudio audio;
		for( int i=0 ; i<current_OurAction->numOfAudioFrames ; i++ )
		{
			if( current_OurAction->audioFrames[i]->frameNO <= current_frame && 
				current_OurAction->audioFrames[i]->frameNO >= current_frame - current_OurAction->play_speed ){
					audio.Object(current_OurAction->audioFrames[i]->audioID);
					audio.Play(ONCE);
					return true;
			}
		}
	}
	return false;
}

bool OurActor::playActionFx()
{
	if( current_OurAction->numOfFxFrames > 0 )
	{
		for( int i=0 ; i<current_OurAction->numOfFxFrames ; i++ )
		{
			if( current_OurAction->fxFrames[i]->frameNO <= current_frame && 
				current_OurAction->fxFrames[i]->frameNO >= current_frame - current_OurAction->play_speed ){
				
					current_OurAction->fxFrames[i]->fx = AllFx::getFX(current_OurAction->fxFrames[i]->fxName, sID);

					   eF3DBaseFX *fx_sub;
					   float pos[3];
					   actor.GetWorldPosition(pos);
					   pos[2] = 50;
						int numFX = current_OurAction->fxFrames[i]->fx->NumberFXs();
						for (int i = 0; i < numFX; i++) {
						  fx_sub = current_OurAction->fxFrames[i]->fx->GetFX(i);
						  fx_sub->InitPosition(pos);
						}

					current_OurAction->fxFrames[i]->fx->Play(5);

			}
			else if(  current_OurAction->fxFrames[i]->frameNO < current_frame )
			{
				if( current_OurAction->fxFrames[i]->fx != NULL )
				{
					bool beOK = current_OurAction->fxFrames[i]->fx->Play(5);
					if( !beOK )
					{
						delete current_OurAction->fxFrames[i]->fx;
						current_OurAction->fxFrames[i]->fx = NULL;
					}
				}
			}
		}
	}
	return false;
}